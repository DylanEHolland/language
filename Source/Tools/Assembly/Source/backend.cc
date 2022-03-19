/**
 * @file backend.cc
 * @author Dylan E. Holland (salinson1138@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <VM/Include/opcode.h>
#include <VM/Include/instruction.h>
#include <Tools/Assembly/Include/parser.h>
#include <Tools/Assembly/Include/backend.h>
#include <Common/Include/output.h>

#include <vector>
#include <iostream>

using namespace liz::vm;
using namespace std;

namespace liz::tools::assembly {
    struct extractOperandResult *extractOperand(std::string operandStr, int lineNumber) {
        bool extracted = false;
        struct intermediateDataValue *extractedData = new struct intermediateDataValue;
        struct extractOperandResult *returnBuffer = new struct extractOperandResult;
        struct intermediateOperand *operand = new struct intermediateOperand;
        operand->type = INVALID_OPERAND_TYPE;
        
        if(operandStr[0] == '\'') {
            operand->type = DATA_OPERAND;
            returnBuffer->data = getCharacterFromOperandString(operandStr, lineNumber);
            extracted = true;
        } else {
            /* assume it is a variable name */
            returnBuffer->data = getNameOrRegisterOperand(operandStr, lineNumber);
            extracted = true;
        }

        if(!extracted) {
            logError("Something went wrong", lineNumber);
        }

        returnBuffer->operand = operand;
        return returnBuffer;
    }

    struct intermediate *createIntermediate(std::vector<struct assemblyLine*> instructionList) {
        int lineNumber = 1;
        int dataCount = 0;
        std::vector<struct intermediateDataValue *> programData;
        struct intermediate *result = new struct intermediate;
        
        for(auto asmLine : instructionList) {
            //dumpAssemblyLine(asmLine);
            auto foundOpcode = opcodeFromString(asmLine->instruction);
            std::vector<struct intermediateOperand *> extractedOperands;

            if(foundOpcode == NO_INSTRUCTION) {
                logError("Instruction not found when trying " + asmLine->instruction);
            }


            for(auto op : asmLine->operands) {
                struct extractOperandResult *operandValue = extractOperand(op, lineNumber);
                if(operandValue->operand->type != INVALID_OPERAND_TYPE) {
                    auto operand = operandValue->operand;
                    if(operand->type == DATA_OPERAND) {
                        programData.push_back(operandValue->data);
                        operand->dataId = dataCount;
                        dataCount++;
                    }

                    extractedOperands.push_back(operand);
                }
            }
            
            for(auto str : asmLine->strings) {
                // TODO: make string an intermediateDataValue
                //programData.push_back(;

                dataCount++;
            }

            // TODO: 

            struct intermediateInstruction *finalInstruction = new struct intermediateInstruction;
            finalInstruction->opcode = foundOpcode;
            result->code.push_back(finalInstruction);
            lineNumber++;
        }

        return result;
    }

    struct intermediateDataValue *getCharacterFromOperandString(std::string operandStr, int lineNumber) {
        struct intermediateDataValue *charNode = new intermediateDataValue;
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

    struct intermediateDataValue *getNameOrRegisterOperand(std::string operandStr, int lineNUmber) {
        struct intermediateDataValue *opNode = new intermediateDataValue;
        cout << operandStr << endl;
        return opNode;
    }

    enum liz::vm::opcode opcodeFromString(std::string potentialInstruction) {
        enum liz::vm::opcode foundOpcode = NO_INSTRUCTION;
        if(potentialInstruction == "imut") {
            foundOpcode = IMUT;
        } else if(potentialInstruction == "mov_string") {
            foundOpcode = MOV_STRING;
        } else if(potentialInstruction == "put_character") {
            foundOpcode = PUT_CHARACTER;
        } else if(potentialInstruction == "set_type") {
            foundOpcode = SET_TYPE;
        }

        return foundOpcode;
    }

    void writeIntermediate(std::string fileName, struct intermediate *program) {
        logOutput("writing object code...");
        for(auto ins : program->code) {
            //Instruction *imIns = new Instruction();
            //imIns->fromIntermediate(ins);
            break;
        }
    }
}