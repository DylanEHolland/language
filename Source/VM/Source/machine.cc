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

#include <iostream>

using namespace std;

namespace liz::vm {
    Machine::Machine() {
        this->memory = new class lizMemory();
        this->boot();
    }

    Machine::~Machine() {

    }

    void Machine::boot() {
        
    }

    void Machine::handleOperands(vector<struct intermediateOperand *> operands) {
        for(auto op : operands) {
            cout << "Found operand" << endl;
        }
    }

    void Machine::run(struct intermediate *blob) {
        for(auto op : blob->code) {
            switch(op->opcode) {
                case NO_INSTRUCTION:
                break;

                case ADD:
                case ALLOCATE:
                case FREE:
                break;
                case IMUT:
                    cout << "imut" << endl;
                    this->handleOperands(op->operands);
                break;
                case MOV_NUMBER:
                case MOV_STRING:
                case MUT:
                case PUT_CHARACTER:
                case RETURN:
                case SET_TYPE:
                break;
            }
        }
    }
}
