add_subdirectory(DataTypes)
add_subdirectory(Memory)

add_library(vm
    Include/opcode.h
    Include/registers.h
    Include/types.h

    Source/opcode.cc
    Source/registers.cc
    Source/types.cc
)