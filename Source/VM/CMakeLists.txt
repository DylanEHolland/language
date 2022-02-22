add_subdirectory(DataTypes)
add_subdirectory(Memory)

add_library(vm
    Include/instruction.h
    Include/opcode.h
    Include/operand.h
    Include/registers.h
    Include/types.h

    Source/instruction.cc
    Source/opcode.cc
    Source/operand.cc
    Source/registers.cc
    Source/types.cc
)