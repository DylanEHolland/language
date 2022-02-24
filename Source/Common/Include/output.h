#pragma once
#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
#include <sstream>
#include <string>


namespace liz {
    std::string addrToStr(void *addr, bool showX = true);
    void logError(std::string e, int line = 0);
    void logOutput(std::string o);    
}

#endif