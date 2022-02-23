#pragma once
#include <VM/Memory/Include/memory.h>

namespace liz::vm {
    enum operandType {
        opValue,
        opRegister,
        opFlag
    };

    struct operand {
        enum operandType type;
    };

    struct operands {
        struct operand o_1;
        struct operand o_2;
        struct operand o_3;
    };
}