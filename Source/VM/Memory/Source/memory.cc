#include <VM/Include/config.h>
#include <VM/Memory/Include/memory.h>
#include <VM/Include/types.h>
#include <VM/DataTypes/Include/number.h>
#include <Common/Include/output.h>

#include <iostream>
#include <sys/mman.h>
#include <string.h>

// #include <sys/stat.h>
// #include <fcntl.h>

// #include <stdlib.h>
// #include <sys/ioctl.h>
// #include <stdio.h>

// #include <unistd.h>

namespace liz::vm {
    bool lizMemory::initializeMemory() {
        bool allocatedMemory = false;
        

        //mlock(mp, n_bytes);
        size_t nPages = (this->memSize / sizeof(struct lizPage));
        
        for(int i = 0; i < nPages; i++) {
            this->createPage();
            break;
            //std::cout << "Allocating page #" << (i+1) << std::endl;
        }

        return allocatedMemory;
    }

    lizMemory::lizMemory() {
        std::cout << "Starting virtual memory system..." << std::endl;    
        if(!this->initializeMemory()) {
            logError("Memory error, aborting.");
            std::exit(-1);
        }
    }   

    lizMemory::~lizMemory() {

    }

    struct lizPage *lizMemory::createPage() {
        size_t numWordBytes = sizeof(struct lizWord);
        size_t numWords = (4096 / numWordBytes);
        
        unsigned char *mp = (unsigned char *)mmap(
            0, 
            4096,
            PROT_READ|PROT_WRITE, 
            MAP_ANONYMOUS | MAP_PRIVATE, 
            -1, 
            0
        );

        if(mp == MAP_FAILED) {
            std::cout << "Initial allocation Failed" << std::endl;
            std::exit(-1);
        }

        struct lizPage *page = (struct lizPage *)mp;
        mp += sizeof(struct lizPage *);

        for(int i = 0; i < numWords; i++) {
           unsigned char *wp = (unsigned char *)mmap(
                mp,
                sizeof(struct lizWord),
                PROT_READ|PROT_WRITE,
                MAP_ANONYMOUS | MAP_PRIVATE,
                -1, 
                0
            );

            if(wp == MAP_FAILED) {
                std::cout << "Word struct allocation Failed" << std::endl;
                std::exit(-1);
            }

            struct lizWord *word = (struct lizWord *)wp;
            mp += 8;

           unsigned char *bp = (unsigned char *)mmap(
                mp,
                16,
                PROT_READ|PROT_WRITE,
                MAP_ANONYMOUS | MAP_PRIVATE,
                -1, 
                0
            );

            if(bp == MAP_FAILED) {
                std::cout << "Allocation of word bytes failed" << std::endl;
                std::exit(-1);
            }

            word->bytes = bp;
            for(int b = 0; b < numWordBytes; b++)
                word->bytes[0] = '\0';

            mp += 8;
        }

        return page;
    }
}