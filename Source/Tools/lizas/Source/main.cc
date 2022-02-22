#include <iostream>
#include <Common/Include/input.h>

int main(int argc, char **argv) {
    if(argc < 2) {
        std::cout << "Error: Please provide a .lizasm file" << std::endl;
        exit(-1);
    }

    for(int i = 1; i < argc; i++) {
        std::cout << "Reading... " << argv[i] << std::endl;
        std::string buffer = liz::common::readFile(argv[i]);
        //buffer;
    }


    return 0;
}