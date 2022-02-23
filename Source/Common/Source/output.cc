#include <Common/Include/output.h>
#include <iostream>
#include <string>

namespace liz {
    void logOutput(std::string o) {
        std::cout << o << std::endl;
    }

    void logError(std::string e, int line) {
        std::string lineDisplay = ": ";
        if(line > 0) {
            lineDisplay = " on line " + std::to_string(line) + " - ";
        }

        std::cout << "Error" << lineDisplay << e << std::endl;
        std::exit(-1);
    }
}