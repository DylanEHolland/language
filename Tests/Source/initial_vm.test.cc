/**
 * @file parse_instructions.test.cc
 * @author Dylan E. Holland (salinson1138@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <Tools/Assembly/Include/parser.h>
#include <Tools/Assembly/Include/backend.h>
#include <VM/Include/machine.h>

using namespace std;
using namespace liz::tools::assembly;

int testRunImut() {
    auto tokens = parseAssemblyCode("imut x\nset_type x, nil");
    auto intermediate = createIntermediate(tokens);

    auto machine = liz::vm::Machine();
    machine.run(intermediate);
    return 0;
}

int main(void) {
    testRunImut();
    return 0;
}
