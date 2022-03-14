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