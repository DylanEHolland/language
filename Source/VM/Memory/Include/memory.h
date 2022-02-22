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
        enum memoryType type;
        enum dataType blockType;
        struct memoryValue valueBlock;
    };
}
