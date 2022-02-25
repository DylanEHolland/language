#include <Common/Include/output.h>
#include <VM/Memory/Include/memory.h>
#include <iostream>

using namespace std;
using namespace liz;
using namespace vm;

void testAllocatorStart() {
    auto al = lizMemory();
    auto addrs = al.getMemSlabOSAddrs();
    std::cout << addrToStr(addrs.head) << std::endl;
    struct lizWord *head = addrs.head;
    while(true) {
        std::cout << addrToStr(head) << std::endl;

        if(head->next == addrs.tail) {
            break;
        } else {
            head = head->next;
        }
    }
}

void testGenerateMemoryBlock() {
    auto al = lizMemory();
    struct generateMemoryBlockResponse block = al.generateMemoryBlock();
    auto numWords = (4096 / sizeof(struct lizWord)); // 170
    struct lizWord *leaf = block.head;
    for(int i = 0; i < 170; i++) {        
        cout << "Found word @" << addrToStr(leaf) << endl;
        leaf = leaf->next;
    }
}

int main(void) {
    testGenerateMemoryBlock();
    testAllocatorStart();
    
    return 0;
}