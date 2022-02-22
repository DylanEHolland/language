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
            //std::cout << n << ". " << line << std::endl;
            parseLineFromAssemblyCode(line);
            n++;
        }
    }

    void parseAssemblyCode(std::string asmCode) {
        if(asmCode[asmCode.length() - 1] != '\n') {
            asmCode += '\n';
        }

        asmCode = removeComments(asmCode);
        std::vector<std::string> asmCodeLines = splitIntoLines(asmCode);
        tokenizeCleanAssemblyCode(asmCodeLines);
    }

    std::vector<std::string> parseLineFromAssemblyCode(std::string asmCodeLine) {
        /* Break line up into tokenized version of opcodes && operands */
        std::vector<std::string> tokenizeLine;

        /* Extract strings from line */
        std::vector<std::string> stringsList;
        std::vector<int> stringBeginList;
        std::string newString = "";
        bool insideString = false;

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
        std::string newAsmCodeLine = "";
        for(auto stringBeginAt : stringBeginList) {
            auto replacerString = stringsList[n];
            bool addedStringPlaceholder = false;
            for(int i = 0; i < asmCodeLine.length(); i++) {
                int endIndex = (stringBeginAt + replacerString.length());
                // TODO: Fix this
                if(i < stringBeginAt-1 || i > endIndex ) { // +1 for now due to parenthesis
                     newAsmCodeLine += asmCodeLine[i];
                }

                if(i > (stringBeginAt-1) && !addedStringPlaceholder) {
                    newAsmCodeLine += "{{#STR:" + std::to_string(i) + "}}";
                    addedStringPlaceholder = true;
                }
            }

            n += 1;
            std::cout << newAsmCodeLine << std::endl;
        }

        
        
        // for(int i = 0; i < asmCodeLine.length(); i++) {
        //     auto character = asmCodeLine[i];
        //     newAsmCodeLine += character;
        // }
        
        //std::cout << asmCodeLine << std::endl;
        //std::cout << newAsmCodeLine << std::endl;

        //

        // for(int i = 0; i < asmCodeLine.length(); i++) {
        //     std::cout << asmCodeLine[i];

        //     if(!insideString) {
                
        //     }
        // }

        return tokenizeLine;
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