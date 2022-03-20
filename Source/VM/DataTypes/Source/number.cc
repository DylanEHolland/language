/**
 * @file number.cc
 * @author Dylan E. Holland (salinson1138@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <VM/DataTypes/Include/number.h>
#include <iostream>
#include <string>

using namespace std;

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

    string number::str() {
        char *buffer = (char *)"this is a test";
        return buffer;
    }

    float number::get() {
        return this->value;
    }
}
