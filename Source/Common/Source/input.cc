#include <Common/Include/input.h>

#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>

using std::filesystem::exists;
using std::filesystem::file_size;

namespace liz::common {
    std::string readFile(std::string fileName) {
        if(exists(fileName)) {
            std::ifstream f(fileName, std::ios::in | std::ios::binary);
            const auto sz = file_size(fileName);
            std::string result(sz, '\0');
            f.read(result.data(), sz);

            return result;
        } else {
            std::cout << "Error: " << fileName << " does not exist" << std::endl;
            exit(-1);
        }
        
        return nullptr;
    }
}