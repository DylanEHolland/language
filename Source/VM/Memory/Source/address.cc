/**
 * @file address.cc
 * @author Dylan E. Holland (salinson1138@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <Common/Include/output.h>
#include <VM/Memory/Include/address.h>
#include <VM/Memory/Include/memory.h>
#include <iostream>

using namespace std;
using namespace liz;

namespace liz::vm {
    lizAddr::lizAddr(struct lizMemory *mem, int addr) {
        if(address < 0) {
            cout << "Invalid memory address";
        }

        this->mem = mem;
        this->address = addr;
        this->fromAddress();
    }

    lizAddr::~lizAddr() {
        cout << endl;
    }

    void lizAddr::mov(char *data) {
        
    }

    void lizAddr::fromAddress() {
        cout << "Starting at address: " << this->address << endl;
        cout << "\tin \"physical\" word: " \
            << (this->address / 16) \
            << " [*startAddress+" \
            << (
                (this->address / 16) * sizeof(struct lizWord)
            ) \
            << "]"
        <<  endl;


        //cout << "\tchar index: " << (this->address % 16) << endl;
        lizWord *addr = this->mem->startAddress;
        addr += (this->address / 16) * sizeof(struct lizWord);
        /* Verify we can manipulate byte */
        char buffer = addr->bytes[0];
        addr->bytes[0] = 'z';
        if(addr->bytes[0] != 'z') {
            cout << "Memory error" << endl;
            exit(-1);
        }

        addr->bytes[0] = buffer;
        this->word = addr;
        this->index = (this->address % 16);
    }

    unsigned char *lizAddr::next(size_t bytes) {
        cout << "Mapping " << bytes << " bytes" << endl;
        unsigned char *buffer;
        return buffer;
    }
};
