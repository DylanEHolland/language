#pragma once
#include <VM/DataTypes/Include/base_type.h>
#include <string>

using namespace std;

namespace liz::vm::dataTypes {
    class number : public baseType {
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