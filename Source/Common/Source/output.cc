#include <Common/Include/output.h>
#include <iostream>
#include <string>

namespace liz {
    std::string addrToStr(void *addr, bool showX) {
        /**
         * @brief Take a point of void* and return a string of its address
         */
        const void * address = static_cast<const void*>(addr);
        std::stringstream ss;
        ss << address;
        std::string output = ss.str();

        return output;
    }

    void logError(std::string e, int line) {
        std::string lineDisplay = ": ";
        if(line > 0) {
            lineDisplay = " on line " + std::to_string(line) + " - ";
        }

        std::cout << "Error" << lineDisplay << e << std::endl;
        std::exit(-1);
    }

    void logOutput(std::string o) {
        std::cout << o << std::endl;
    }
}