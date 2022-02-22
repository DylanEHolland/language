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
#include <string>
#include <iostream>
#include <vector>

namespace liz::tools::assembly {

    // void createIntermediate(std::vector<std::string> asmCodeLines) {
    //     int n = 0;
    //     for(auto line : asmCodeLines) {
    //         std::cout << n << ". " << line << std::endl;
    //         n++;
    //     }
    // }

    void tokenizeCleanAssemblyCode(std::vector<std::string> asmCodeLines) {
        int n = 0;
        std::vector<std::string> instructionTokens;
        std::vector<std::string> lineTokens;

        for(auto line : asmCodeLines) {
            std::cout << n << ". " << line << std::endl;
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