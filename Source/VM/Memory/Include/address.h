#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H

#include <VM/Memory/Include/memory.h>

namespace liz::vm {
    class lizAddr {
        int address = 0;
        int index = 0;
        class lizMemory *mem;
        struct lizWord *word;

        void fromAddress();

        public:
            lizAddr(struct lizMemory *mem, int addr);
            ~lizAddr();
            unsigned char *next(size_t bytes);
            void mov(char *data);
    };
}

#endif
