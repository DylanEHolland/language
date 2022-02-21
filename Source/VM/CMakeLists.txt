add_subdirectory(DataTypes)

add_library(vm
    Include/memory.h
    Include/opcode.h
    Include/registers.h
    Include/types.h

    Source/memory.cc
    Source/opcode.cc
    Source/registers.cc
    Source/types.cc
)