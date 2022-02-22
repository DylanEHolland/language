#pragma once
#include <string>

namespace liz::tools::assembly {
    // void createIntermediate(std::vector<std::string> asmLines);
    void tokenizeCleanAssemblyCode(std::vector<std::string> asmLines);
    std::vector<std::string> splitIntoLines(std::string asmCode);
    void parseAssemblyCode(std::string asmCode);
    std::string removeComments(std::string asmCode);
}