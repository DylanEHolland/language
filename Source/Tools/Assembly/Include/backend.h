#pragma once

#include <VM/Include/opcode.h>
#include <Tools/Assembly/Include/parser.h>
#include <vector>

namespace liz::tools::assembly {
    enum allowedIntermediateTypes {
        INVALID = 0,
        CHAR
    };

    struct asmIntermediateValue {
        enum allowedIntermediateTypes type;
        char char_value;
    };

    void createIntermediate(std::vector<struct assemblyLine*> instructionList);
    enum liz::vm::opcode opcodeFromString(std::string potentialInstruction);
    struct asmIntermediateValue *getCharacterFromOperandString(std::string operandStr, int lineNUmber);
    struct asmIntermediateValue *extractOperand(std::string operand, int lineNumber);
}