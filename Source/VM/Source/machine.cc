#include <VM/Memory/Include/memory.h>
#include <VM/Include/machine.h>
#include <VM/Include/instruction.h>

namespace liz::vm {
    Machine::Machine() {
        this->memory = new class lizMemory();
        this->boot();
    }

    Machine::~Machine() {

    }

    void Machine::boot() {
        
    }

    void Machine::run(struct intermediate *blob) {

    }
}