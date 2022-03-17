#pragma once
#include <VM/DataTypes/Include/base_type.h>

namespace liz::vm::dataTypes {
    class number : public baseType {
        public:
            number(float x);
            number(int x);
            void set(float x);
            char *str();
            float get();

        private:
            float value;
    };
}