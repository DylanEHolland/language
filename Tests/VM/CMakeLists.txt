add_subdirectory(Memory)
add_subdirectory(DataTypes)

add_executable(test_opcodes
    Source/opcodes.test.cc
)

add_executable(test_registers
    Source/registers.test.cc
)

add_executable(test_types
    Source/types.test.cc
)

target_link_libraries(test_opcodes common vm)
target_link_libraries(test_registers common vm)
target_link_libraries(test_types common vm)