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

namespace liz::vm {
    enum opcode {
        NO_INSTRUCTION = 0,
        
        ADD,  
        ALLOCATE,
        FREE,
        IMUT,
        MOV_NUMBER,
        MOV_STRING,
        MUT,
        PUT_CHARACTER,
        RETURN,
        SET_TYPE
    };
}