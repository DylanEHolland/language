#include <VM/DataTypes/Include/base_type.h>
#include <iostream>

using namespace liz::vm::dataTypes;
using namespace std;

void testBaseTypeStr() {
    for(int i = 0; i < 1; i++) {
        auto n = new baseType();
        cout << n->str() << endl;
    }
}

int main(void) {
    testBaseTypeStr();

    return 0;
}