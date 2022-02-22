#include <iostream>
#include <Common/Include/input.h>
#include <Tools/Assembly/Include/parser.h>

int main(int argc, char **argv) {
    if(argc < 2) {
        std::cout << "Error: Please provide a .lizasm file" << std::endl;
        exit(-1);
    }

    for(int i = 1; i < argc; i++) {
        std::string buffer = liz::common::readFile(argv[i]);
        liz::tools::assembly::parseAssemblyCode(buffer);
    }

    return 0;
}