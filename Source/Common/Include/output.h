#pragma once
#include <iostream>

namespace liz {
    void logOutput(std::string o);
    void logError(std::string e, int line = 0);
}