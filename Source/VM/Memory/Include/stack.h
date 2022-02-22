#pragma once

namespace liz::vm::memory {
    struct stackRow {
        struct stackRow *previous;
        struct memoryCell *item;
    };
};