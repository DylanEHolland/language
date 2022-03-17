/**
 * @file parser.h
 * @author Dylan E. Holland (salinson1138@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <string>
#include <vector>

namespace liz::tools::assembly {
    struct extractedAssemblyLine {
        std::string line;
        std::vector<std::string> storedStrings;
    };

    struct assemblyLine {
        std::vector<std::string> strings;
        std::vector<std::string> operands;
        std::string instruction;
    };

    struct assemblyLine *parseLineFromAssemblyCode(std::string asmCodeLine);
    std::vector<struct assemblyLine*> tokenizeCleanAssemblyCode(std::vector<std::string> asmLines);
    std::vector<std::string> splitIntoLines(std::string asmCode);
    std::vector<struct assemblyLine*> parseAssemblyCode(std::string asmCode);
    std::string removeComments(std::string asmCode);
    struct extractedAssemblyLine *extractStringsFromLine(std::string asmCodeLine);
    void dumpAssemblyLine(struct assemblyLine *node);
}