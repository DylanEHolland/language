/**
 * @file nil.h
 * @author Dylan E. Holland (salinson1138@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <VM/DataTypes/Include/atom.h>

namespace liz::vm::dataTypes {
    class nil : public dataTypes::atom {
        public:
            nil();
    };
}