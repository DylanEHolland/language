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
    void tokenizeCleanAssemblyCode(std::vector<std::string> asmLines);
    std::vector<std::string> splitIntoLines(std::string asmCode);
    void parseAssemblyCode(std::string asmCode);
    std::string removeComments(std::string asmCode);
    struct extractedAssemblyLine *extractStringsFromLine(std::string asmCodeLine);
    void dumpAssemblyLine(struct assemblyLine *node);
}