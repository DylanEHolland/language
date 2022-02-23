#include <Tools/Assembly/Include/parser.h>
#include <Tools/Assembly/Include/backend.h>
#include <VM/Include/opcode.h>
#include <VM/Include/instruction.h>
#include <Common/Include/output.h>

#include <vector>
#include <iostream>

using namespace liz::vm;

namespace liz::tools::assembly {
    struct asmIntermediateValue *extractOperand(std::string operandStr, int lineNumber) {
        bool extracted = false;
        struct asmIntermediateValue *extractedOp = new struct asmIntermediateValue;
        extractedOp->type = INVALID;

        if(operandStr[0] == '\'') {
            extractedOp = getCharacterFromOperandString(operandStr, lineNumber);
            std::string charDisplay = "";
            extracted = true;
        } else {
            /* assume it is a variable name */
            extracted = true;
        }

        if(!extracted) {
            logError("Something went wrong", lineNumber);
        }

        return extractedOp;
    }

    void createIntermediate(std::vector<struct assemblyLine*> instructionList) {
        int lineNumber = 1;
        int stringCount = 0;
        std::vector<std::string> programStrings;
        
        for(auto asmLine : instructionList) {
            //dumpAssemblyLine(asmLine);
            auto foundOpcode = opcodeFromString(asmLine->instruction);
            std::vector<struct asmIntermediateValue *> extractedOperands;

            if(foundOpcode == NO_INSTRUCTION) {
                logError("Instruction not found when trying " + asmLine->instruction);
            }


            for(auto op : asmLine->operands) {
                struct asmIntermediateValue *operandValue = extractOperand(op, lineNumber);
                if(operandValue->type != INVALID) {
                    extractedOperands.push_back(operandValue);
                }
            }
            
            for(auto str : asmLine->strings) {
                programStrings.push_back(str);
                stringCount += 1;
            }

            lineNumber++;
        }
    }

    struct asmIntermediateValue *getCharacterFromOperandString(std::string operandStr, int lineNumber) {
        struct asmIntermediateValue *charNode = new asmIntermediateValue;
        bool foundOpenQuote = false;
        bool foundClosedQuote = false;
        bool breakingChar = false;

        bool foundChar = false;
        char characterFound;

        for(int i = 0; i < operandStr.length(); i++) {
            if(foundOpenQuote && foundClosedQuote && foundChar) {
                /* If we've parsed but still have characters */
                logError("Character declaration invalid", lineNumber);
            }

            if(foundClosedQuote) {
                break;
            }

            char c = operandStr[i];
            if(!breakingChar && foundOpenQuote && foundChar && c != '\'') {
                logError("Character operand is invalid - " + operandStr, lineNumber);
            }

            if(!breakingChar && c == '\\') {
                breakingChar = true;
            } else {
                if(!foundOpenQuote) {
                    if(!breakingChar && c == '\'') {
                        foundOpenQuote = true;
                    }
                } else {
                    if(!breakingChar && c == '\'') {
                        foundClosedQuote = true;
                    } else {
                        foundChar = true;
                        characterFound = c;
                    }
                }
            }

            if(i > 0 && breakingChar && operandStr[i-1]) {
                breakingChar = false;
            }
        }
        
        charNode->type = CHAR;
        charNode->char_value = characterFound;

        return charNode;
    }

    enum liz::vm::opcode opcodeFromString(std::string potentialInstruction) {
        enum liz::vm::opcode foundOpcode = NO_INSTRUCTION;        
        
        if(potentialInstruction == "mov_string") {
            foundOpcode = MOV_STRING;
        } else if(potentialInstruction == "put_character") {
            foundOpcode = PUT_CHARACTER;
        }

        return foundOpcode;
    }
}