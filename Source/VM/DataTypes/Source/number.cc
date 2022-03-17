#include <VM/DataTypes/Include/number.h>
#include <iostream>

namespace liz::vm::dataTypes {
    number::number(float x) {
        this->value = x;
    }

    number::number(int x) {
        this->value = (float)x;
    }

    void number::set(float x) {
        this->value = x;
    }

    char *number::str() {
        char *buffer = (char *)"this is a test";
        return buffer;
    }

    float number::get() {
        return this->value;
    }
}