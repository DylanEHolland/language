#pragma once
#include <string>

namespace liz::tools::assembly {
    std::vector<std::string> parseLineFromAssemblyCode(std::string asmCodeLine);
    void tokenizeCleanAssemblyCode(std::vector<std::string> asmLines);
    std::vector<std::string> splitIntoLines(std::string asmCode);
    void parseAssemblyCode(std::string asmCode);
    std::string removeComments(std::string asmCode);
}