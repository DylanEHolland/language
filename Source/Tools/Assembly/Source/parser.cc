/**
 * @file parser.cc
 * @author Dylan E Holland <salinson1138@gmail.com>
 * @brief 
 * @version 0.1
 * @date 2022-02-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Tools/Assembly/Include/parser.h>

#include <iostream>
#include <string>
#include <vector>


namespace liz::tools::assembly {
    void tokenizeCleanAssemblyCode(std::vector<std::string> asmCodeLines) {
        int n = 0;
        std::vector<std::string> instructionTokens;
        std::vector<std::string> lineTokens;

        for(auto line : asmCodeLines) {
            auto asmLine = parseLineFromAssemblyCode(line);
            dumpAssemblyLine(asmLine);
            n++;
        }
    }

    void dumpAssemblyLine(struct assemblyLine *node) {
        std::string output = "";
        bool hasOps = false;

        if(node->instruction.length() > 0) {
            output += node->instruction;
        }

        for(auto oper : node->operands) {
            hasOps = true;
            output += " " + oper;
        }

        if(hasOps && node->strings.size() > 0) {
            output += " -> ";
        }

        for(auto str : node->strings) {
            output += "\"" + str + "\" ";
        }

        std::cout << output << std::endl;
    }

    struct extractedAssemblyLine *extractStringsFromLine(std::string asmCodeLine) {
        std::vector<std::string> stringsList;
        std::vector<int> stringBeginList;
        std::string newString = "";
        bool insideString = false;
        struct extractedAssemblyLine *lineBuffer = new struct extractedAssemblyLine();

        for(int i = 0; i < asmCodeLine.length(); i++) {
            auto character = asmCodeLine[i];

            if(character == '\"') {
                insideString = !insideString;
                if(!insideString) {
                    /* if just turned off */
                    stringsList.push_back(newString);
                    newString = "";           
                } else {
                    /* or else just turned on */
                    stringBeginList.push_back(i + 1);
                }
            } else {
                if(insideString) {
                    newString += character;
                }
            }
        }

        int n = 0;
        std::string currentUpdatedLine = asmCodeLine;
        int workingStringLength = asmCodeLine.length();
        int shortenBeginCharBy = 0;
        for(auto stringBeginAt : stringBeginList) {
            std::string workingLineBuffer = "";
            auto replacerString = stringsList[n];
            bool addedStringPlaceholder = false;
            stringBeginAt -= shortenBeginCharBy;

            for(int i = 0; i < currentUpdatedLine.length(); i++) {
                int endIndex = (stringBeginAt + replacerString.length());
                // TODO: Fix this
                if(i < stringBeginAt-1 || i > endIndex ) { // +1 for now due to parenthesis
                     workingLineBuffer += currentUpdatedLine[i];
                }

                if(i > (stringBeginAt-1) && !addedStringPlaceholder) {
                    workingLineBuffer += "{{#STR:" + std::to_string(n) + "}}";
                    addedStringPlaceholder = true;
                }
            }

            n += 1;

            currentUpdatedLine = workingLineBuffer;
            int lineLengthDiff = (workingStringLength - workingLineBuffer.length());
            if(lineLengthDiff > 0) {
                shortenBeginCharBy += lineLengthDiff;
            }

            workingStringLength = currentUpdatedLine.length();
        }

        lineBuffer->line = currentUpdatedLine;
        lineBuffer->storedStrings = stringsList;

        return lineBuffer;
    }

    void parseAssemblyCode(std::string asmCode) {
        if(asmCode[asmCode.length() - 1] != '\n') {
            asmCode += '\n';
        }

        asmCode = removeComments(asmCode);
        std::vector<std::string> asmCodeLines = splitIntoLines(asmCode);
        tokenizeCleanAssemblyCode(asmCodeLines);
    }

    struct assemblyLine *parseLineFromAssemblyCode(std::string asmCodeLine) {
        auto assemblyLineBuffer = new struct assemblyLine;
        auto extractedLine = extractStringsFromLine(asmCodeLine);
        auto line = extractedLine->line;

        bool storedInstruction = false;
        bool resetBuffer = false;
        std::string buffer = "";
        bool trimming = false;

        for(int i = 0; i < line.length(); i++) {
            auto character = line[i];
            bool addChar = true;

            if(resetBuffer) {
                buffer = "";
                resetBuffer = false;
            }

            if(character == ' ' && !storedInstruction) {
                assemblyLineBuffer->instruction = buffer;
                storedInstruction =  true;
                resetBuffer = true;
                addChar = false;
            } else if(character == ' ' && storedInstruction) {
                addChar = false;
            } else if(storedInstruction && character == ',') {
                assemblyLineBuffer->operands.push_back(buffer);
                resetBuffer = true;
                addChar = false;
            }

            if(addChar) {
                buffer += character;
            }
        }

        if(buffer.length() > 0) {
            if(!storedInstruction) {
                assemblyLineBuffer->instruction = buffer;
            } else {
                assemblyLineBuffer->operands.push_back(buffer);
            }
        }

        assemblyLineBuffer->strings = extractedLine->storedStrings;
        return assemblyLineBuffer;
    }

    std::vector<std::string> splitIntoLines(std::string asmCode) {
        /* Break */

        std::vector<std::string> newCodeBuffer;
        std::string lineBuffer = "";

        for(int i = 0; i < asmCode.length(); i++) {
            auto character = asmCode[i];
            
            if(character == '\n') {
                if(lineBuffer.length() > 0) {
                    newCodeBuffer.push_back(lineBuffer);
                    lineBuffer = "";
                }
                
            } else {
                lineBuffer += character;
            }
        }

        return newCodeBuffer;
    }

    std::string removeComments(std::string asmCode) {
        bool skip = false;
        std::string newCodeBuffer = "";

        for(int i = 0; i < asmCode.length(); i++) {
            auto character = asmCode[i];

            if(character == ';') {
                skip = true;
            } else if(character == '\n') {
                skip = false;
            }

            if(!skip) {
                newCodeBuffer += character;
            }
        }

        return newCodeBuffer;
    }
}