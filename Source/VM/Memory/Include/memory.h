#pragma once
#ifndef MEMORY_H
#define MEMORY_H

#include <VM/Include/config.h>
#include <VM/Include/types.h>
#include <VM/DataTypes/Include/number.h>
#include <VM/Include/machine.h>

#define WORD_BYTES (LIZ_WORD_SIZE / 8)
#define WORDS_PER_PAGE ((LIZ_PAGE_SIZE / WORD_BYTES) - 1)

namespace liz::vm {

    #pragma pack(push, 1)
        struct lizWord {
            unsigned char *bytes;
        };
    #pragma pack(pop)


    #pragma pack(push, 1)
        struct lizPage {
            /* Subtract one byte for the next pointer */
            
            struct lizWord *words;
            struct lizPage *next;
        };
    #pragma pack(pop)

    class lizMemory {
        struct lizPage * createPage();
        bool initializeMemory();
        struct lizWord *startAddress;
        int64_t memSize = (4096 * 1024); // 4 megabytes

        public:
            lizMemory();
            ~lizMemory();
    };
}

#endif