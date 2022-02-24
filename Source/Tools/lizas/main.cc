#include <iostream>
#include <Common/Include/input.h>
#include <Tools/Assembly/Include/parser.h>
#include <Tools/Assembly/Include/backend.h>

using namespace liz::tools::assembly;
using namespace liz::common;

int main(int argc, char **argv) {
    if(argc < 2) {
        std::cout << "Error: Please provide a .lizasm file" << std::endl;
        exit(-1);
    }

    for(int i = 1; i < argc; i++) {
        std::string buffer = readFile(argv[i]);
        auto tokens = parseAssemblyCode(buffer);
        auto intermediate = createIntermediate(tokens);
        //writeIntermediate("/tmp/test.lizobj", intermediate);
    }

    return 0;
}