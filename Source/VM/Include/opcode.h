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