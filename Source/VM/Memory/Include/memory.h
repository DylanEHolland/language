/**
 * @file memory.h
 * @author Dylan E. Holland (salinson1138@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#ifndef MEMORY_H
#define MEMORY_H

#include <VM/Include/config.h>
#include <VM/Include/machine.h>

#define WORD_BYTES (LIZ_WORD_SIZE / 8)
#define WORDS_PER_PAGE ((LIZ_PAGE_SIZE / WORD_BYTES) - 1)

namespace liz::vm {

    #pragma pack(push, 1)
        struct lizWord {
            unsigned char bytes[16];
            struct lizWord *next;
        };
    #pragma pack(pop)

    struct generateMemoryBlockResponse {
        struct lizWord *head;
        struct lizWord *tail;
    };

    class lizMemory {
        #ifdef LIZ_TESTING
        public:
        #endif
        bool isInitialized = false;
        void *byVirtualAddress(int64_t addr);
        void expandMemory(int blocks = 1);
        struct generateMemoryBlockResponse generateMemoryBlock();
        void initializeMemory();
        int64_t memBlockSize = (1024 * 12);
        int64_t memSize = (4096 * 12); // initial memory allocation
        int64_t maxMemSize = (1024 * 1024); // 1mb
        int32_t blocksAllocated = 0;
        struct lizWord *startAddress;
        struct lizWord *endAddress;

        #ifndef LIZ_TESTING
        public:
        #endif
            lizMemory();
            ~lizMemory();
            struct generateMemoryBlockResponse getMemSlabOSAddrs();
            void *allocate(size_t bytes);
    };

}

#endif
