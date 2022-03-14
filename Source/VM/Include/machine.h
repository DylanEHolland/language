#pragma once
#ifndef MACHINE_H
#define MACHINE_H

#include <VM/Memory/Include/memory.h>
#include <VM/Include/instruction.h>

namespace liz::vm {
    class Machine {
        public:
            Machine();
            ~Machine();
            void run(struct intermediate *blob);
        private:
            class lizMemory *memory;
            void boot();

    };
}

#endif