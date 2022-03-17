/**
 * @file machine.h
 * @author Dylan E. Holland (salinson1138@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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