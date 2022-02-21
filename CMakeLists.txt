cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
project(liz)

# Libraries


# Source/VM
add_library(vm
    Source/VM/Include/memory.h
    Source/VM/Include/opcode.h
    Source/VM/Include/registers.h
    Source/VM/Include/types.h

    Source/VM/Source/memory.cc
    Source/VM/Source/opcode.cc
    Source/VM/Source/registers.cc
    Source/VM/Source/types.cc
)

# Source/VM/DataTypes
add_library(data_types
    Source/VM/DataTypes/Include/number.h

    Source/VM/DataTypes/Source/number.cc
)

# Source/Common
add_library(common
    Source/Common/Include/input.h

    Source/Common/Source/input.cc
)

# Executables

add_executable(lizas
    Source/Tools/lizas/main.cc
)

add_executable(lizdis
    Source/Tools/lizdis/main.cc
)

add_executable(lizvm
    Source/Tools/lizvm/main.cc
)

# Link all libraries
target_link_libraries(vm data_types common)
target_link_libraries(lizas vm common data_types)
target_link_libraries(lizdis vm common data_types)
target_link_libraries(lizvm vm common data_types)

# Setup include paths
target_include_directories(
    vm
    PUBLIC
        "Source"
)

target_include_directories(
    data_types
    PUBLIC
        "Source"
)

target_include_directories(
    common
    PUBLIC
        "Source"
)