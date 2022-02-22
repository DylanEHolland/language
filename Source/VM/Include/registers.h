#pragma once
#include <VM/Memory/Include/memory.h>

namespace liz::vm {
    /*
        Special registers for underlying functionality
    */
    enum vmFlagType {
        VM_VERSION
    };

    /*
        General purpose registers
    */
    enum vmRegisterType {
        STACK_TOP,
        PROGRAM_COUNTER
    };

    struct vmRegister {
        enum vmRegisterType type;
    };

    struct vmRegisters {
        struct stackRegisters {
            struct vmRegister *top;
        };
    };

    struct vmRegisterValue {
        
    };
}