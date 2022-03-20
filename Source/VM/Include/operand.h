/**
 * @file operand.h
 * @author Dylan E. Holland (salinson1138@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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
