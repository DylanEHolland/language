/**
 * @file memory.test.cc
 * @author Dylan E. Holland (salinson1138@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Common/Include/output.h>
#include <VM/Memory/Include/memory.h>
#include <iostream>

using namespace std;
using namespace liz;
using namespace vm;

void testWord(struct lizWord *word) {
    for(int n = 0; n < 16; n++) {
        cout << \
            "\t-> Verifying byte @" \
            << addrToStr((void *)(size_t)word->bytes[n]) \
        << endl;
        
        word->bytes[n] = 'X';

        cout << \
            "\t\t-> set to: " \
            << word->bytes[n] \
        << endl;
    }
}

void testAllocateBytes() {
    auto al = lizMemory();
    auto byte = al.allocate(16);
}

void testByVirtualAddress() {
    auto al = lizMemory();
    //auto addr = lizAddr();
    // auto addr = al.byVirtualAddress(-0xFF);
    // if(!addr) {
    //     addr = al.byVirtualAddress(0x00);
    //     if(!addr) {
    //         cout << "got nullptr, failed" << endl;
    //         exit(-1);
    //     }
    // } else {
    //     cout << "nullptr check failed" << endl;
    //     exit(-1);
    // }
}

void testAllocatorStart() {
    auto al = lizMemory();
    auto addrs = al.getMemSlabOSAddrs();
    std::cout << addrToStr(addrs.head) << std::endl;
    struct lizWord *head = addrs.head;
    while(true) {
        std::cout << addrToStr(head) << std::endl;
        testWord(head);

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
        testWord(leaf);
        leaf = leaf->next;
    }
}

int main(void) {
    // testGenerateMemoryBlock();
    // testAllocatorStart();
    //testAllocateBytes();
    testByVirtualAddress();

    return 0;
}
