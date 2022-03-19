/**
 * @file instruction.h
 * @author Dylan E. Holland (salinson1138@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <VM/Include/opcode.h>

#include <vector>
#include <string>

namespace liz::vm {
    enum allowedIntermediateDataTypes {
        INVALID = 0,
        CHAR,
        STR
    };

    struct intermediateDataValue {
        enum allowedIntermediateDataTypes type;
        char char_value;
        std::string string_value;
    };

    enum allowedIntermediateOperandTypes {
        INVALID_OPERAND_TYPE = 0,

        DATA_OPERAND,
        REGISTER_OPERAND,
        NAME_OPERAND, 
        TYPE_OPERAND
    };

    struct intermediateOperand { 
        enum allowedIntermediateOperandTypes type;
        int dataId = 0;
    };

    struct intermediateInstruction {
        enum liz::vm::opcode opcode;
        std::vector<struct intermediateOperand *> operands;
    };

    struct intermediate {
        std::vector<struct intermediateInstruction *> code;
        std::vector<intermediateDataValue *> data;
    };

    class Instruction {
        public:
            Instruction();
            ~Instruction();
            void toByteCode();
            void fromIntermediate(struct intermediateInstruction *ins);
        private:
            enum liz::vm::opcode opcode;
    };

    class Instruction *fromByteCodeInstruction();
    void intermediateInstructionToBytes(struct intermediateInstruction *ins);
}