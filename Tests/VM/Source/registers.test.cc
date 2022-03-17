/**
 * @file registers.test.cc
 * @author Dylan E. Holland (salinson1138@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <VM/Include/registers.h>
#include <VM/Memory/Include/memory.h>
#include <iostream>

using namespace liz::vm;
using namespace std;

void testInitializeRegisters() {
    auto mem = new lizMemory();
    initializeRegisters(mem);
    cout << "Testing..." << endl;
}

int main(void) {
    testInitializeRegisters();
    return 0;
}