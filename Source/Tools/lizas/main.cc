/**
 * @file main.cc
 * @author Dylan E. Holland (salinson1138@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <Common/Include/input.h>
#include <Tools/Assembly/Include/parser.h>
#include <Tools/Assembly/Include/backend.h>
#include <VM/Include/machine.h>
#include <VM/Memory/Include/memory.h>

using namespace liz::tools::assembly;
using namespace liz::common;

int main(int argc, char **argv) {
    auto machine = liz::vm::Machine();

    if(argc < 2) {
        std::cout << "Error: Please provide a .lizasm file" << std::endl;
        exit(-1);
    }

    for(int i = 1; i < argc; i++) {
        std::string buffer = readFile(argv[i]);
        auto tokens = parseAssemblyCode(buffer);
        auto intermediate = createIntermediate(tokens);
        //writeIntermediate("/tmp/test.lizobj", intermediate);
        machine.run(intermediate);
    }

    return 0;
}
