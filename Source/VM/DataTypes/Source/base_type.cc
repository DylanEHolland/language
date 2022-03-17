#include <VM/DataTypes/Include/base_type.h>
#include <iostream>
#include <string>

using namespace std;

namespace liz::vm::dataTypes {
    static int head = 0;

    baseType::baseType() {
        this->id = head;
        head++;
    }

    string baseType::str() {
        return to_string(this->id);
    }
}