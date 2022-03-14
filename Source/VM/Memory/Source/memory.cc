#include <VM/Include/config.h>
#include <VM/Memory/Include/memory.h>
#include <VM/Include/types.h>
#include <VM/DataTypes/Include/number.h>
#include <Common/Include/output.h>

#include <iostream>
#include <sys/mman.h>
#include <string.h>

using namespace std;

namespace liz::vm {
    void *lizMemory::allocate(size_t bytes) {
        unsigned char *test;
        cout << "Allocating " << bytes << endl;
        return (void *)(size_t)test;
    }

    void *lizMemory::byVirtualAddress(int64_t addr) {
        if(addr < 0) return nullptr;
        
        return nullptr;
    }

    void lizMemory::expandMemory(int blocks) {
        for(int i = 0; i < blocks; i++) {
            auto block = this->generateMemoryBlock();

            if(!this->isInitialized) {
                this->startAddress = block.head;
                this->endAddress = block.tail;
                this->isInitialized = true;
            } else {
                this->endAddress->next = block.head;
                this->endAddress = block.tail;
            }
        }
    }

    struct generateMemoryBlockResponse lizMemory::generateMemoryBlock() {
        struct generateMemoryBlockResponse response;
        struct lizWord *previous;
        struct lizWord *cell;
        unsigned char *mp = (unsigned char *)mmap(
            0, 
            this->memBlockSize,
            PROT_READ | PROT_WRITE, 
            MAP_ANONYMOUS | MAP_PRIVATE, 
            -1, 
            0
        );
        
        if(mp == MAP_FAILED) {
            std::cout << "generateMemoryBlock: failure on block" \
                << this->blocksAllocated << std::endl;
            std::exit(-1);
        }

        mlock(mp, this->memBlockSize);
        for(int i = 0; i < this->memBlockSize / sizeof(struct lizWord); i++) {
            cell = (struct lizWord *)mp;
            if(i == 0) response.head = cell;
            else previous->next = cell;
            mp += 16;
            previous = cell;
        }

        this->blocksAllocated++;
        response.tail = cell;
        
        return response;
    }

    struct generateMemoryBlockResponse lizMemory::getMemSlabOSAddrs() {
        struct generateMemoryBlockResponse buffer;

        buffer.head = this->startAddress;
        buffer.tail = this->endAddress;

        return buffer;
    }

    void lizMemory::initializeMemory() {
        //this->expandMemory(500);
        // unsigned char *mp = (unsigned char *)mmap(
        //     0, 
        //     1024*10,
        //     PROT_READ | PROT_WRITE, 
        //     MAP_ANONYMOUS | MAP_PRIVATE, 
        //     -1, 
        //     0
        // );
    }

    lizMemory::lizMemory() {
        this->initializeMemory();
    }

    lizMemory::~lizMemory() {

    }

}