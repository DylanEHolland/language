/**
 * @file base_type.cc
 * @author Dylan E. Holland (salinson1138@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

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