#include <VM/Include/config.h>
#include <VM/Memory/Include/memory.h>
#include <VM/Include/types.h>
#include <VM/DataTypes/Include/number.h>
#include <Common/Include/output.h>

#include <iostream>
#include <sys/mman.h>
#include <string.h>

namespace liz::vm {
    void lizMemory::expandMemory(int blocks) {
        for(int i = 0; i < blocks; i++) {
            auto block = this->generateMemoryBlock();

            if(!this->isInitialized) {
                this->startAddress = block.head;
                this->endAddress = block.tail;
                this->isInitialized = true;
            } 
        }
    }

    struct generateMemoryBlockResponse lizMemory::generateMemoryBlock() {
        struct generateMemoryBlockResponse response;
        unsigned char *mp = (unsigned char *)mmap(
            0, 
            this->memBlockSize,
            PROT_READ | PROT_WRITE, 
            MAP_ANONYMOUS | MAP_PRIVATE, 
            -1, 
            0
        );
        mlock(mp, this->memBlockSize);
        
        if(mp == MAP_FAILED) {
            std::cout << "generateMemoryBlock: failure on block" << this->blocksAllocated << std::endl;
            std::exit(-1);
        }
        struct lizWord *previous;
        struct lizWord *cell;
        for(int i = 0; i < this->memBlockSize / sizeof(struct lizWord); i++) {
            cell = (struct lizWord *)mp;
            cell->next = previous;
            if(i == 0) response.head = cell;
            mp += 16;

            previous = cell;
        }
        
        response.tail = cell;
        this->blocksAllocated++;
        return response;
    }

    void lizMemory::initializeMemory() {
        this->expandMemory(2);
    }

    lizMemory::lizMemory() {
        std::cout << "Starting virtual memory system..." << std::endl;    
        this->initializeMemory();
    }

    lizMemory::~lizMemory() {

    }
}