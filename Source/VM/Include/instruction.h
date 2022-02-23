#pragma once
#include <VM/Include/opcode.h>

#include <vector>

namespace liz::vm {
    struct intermediateInstruction {
        enum liz::vm::opcode opcode;
        std::vector<struct asmIntermediateValue *> operands;
    };


    class Instruction {
        public:
            Instruction();
            ~Instruction();
            void toByteCode();
        private:
    };

    class Instruction *fromByteCodeInstruction();
}