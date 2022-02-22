#pragma once

#include <VM/Include/types.h>
#include <VM/DataTypes/Include/number.h>

namespace liz::vm {
    enum memoryType {
        value,
        pointer,
        variable
    };

    struct memoryValue {
        class number *numberValue;
    };

    struct memoryCell {
        int address;
        enum memoryType type;
        enum dataType blockType;
        struct memoryValue valueBlock;
        bool dead;
    };

    struct memory {
        struct stackRow *stackTop;
        struct memoryCell *freed;
        struct memoryCell *used;
    };
}
