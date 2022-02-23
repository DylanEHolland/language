#include <VM/Include/instruction.h>
#include <Common/Include/output.h>

namespace liz::vm {
    Instruction::Instruction() {

    }

    Instruction::~Instruction() {
        
    }

    void Instruction::toByteCode() {
        
    }

    void Instruction::fromIntermediate(struct intermediateInstruction *ins) {
        //ins->opcode
    }

    class Instruction *fromByteCodeInstruction() {
        class Instruction *buffer = new Instruction();

        return buffer;
    }

    void intermediateInstructionToBytes(struct intermediateInstruction *ins) {
        
    }
}