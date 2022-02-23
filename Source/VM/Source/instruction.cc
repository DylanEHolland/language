#include <VM/Include/instruction.h>

namespace liz::vm {
    Instruction::Instruction() {

    }

    Instruction::~Instruction() {
        
    }

    void Instruction::toByteCode() {
        
    }

    class Instruction *fromByteCodeInstruction() {
        class Instruction *buffer = new Instruction();

        return buffer;
    }
}