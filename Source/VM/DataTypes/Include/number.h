/**
 * @file number.h
 * @author Dylan E. Holland (salinson1138@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <VM/DataTypes/Include/atom.h>
#include <string>

using namespace std;

namespace liz::vm::dataTypes {
    class number : public atom {
        public:
            number(float x);
            number(int x);
            void set(float x);
            string str();
            float get();

        private:
            float value;
    };
}
