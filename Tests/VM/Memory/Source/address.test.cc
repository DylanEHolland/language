#include <iostream>
#include <VM/Memory/Include/address.h>
#include <VM/Memory/Include/memory.h>

using namespace liz::vm;
using namespace std;

void testFetchingAddress() {
    auto mem = new lizMemory();
    auto addr = new lizAddr(mem, 1027);
    addr->next(32);
    return;
    for(int i = 0; i < 32; i++) {
        auto addr = new lizAddr(mem, i);
        addr->next(512);
    }

    
}

int main(void) {
    testFetchingAddress();
    return 0;
}