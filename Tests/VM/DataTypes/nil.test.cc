/**
 * @file base_type.test.cc
 * @author Dylan E. Holland (salinson1138@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <VM/DataTypes/Include/nil.h>
#include <iostream>

using namespace liz::vm::dataTypes;
using namespace std;

void testNilStr() {
    for(int i = 0; i < 1; i++) {
        auto n = new nil();
        cout << n->str() << endl;
    }
}

int main(void) {
    testNilStr();

    return 0;
}
