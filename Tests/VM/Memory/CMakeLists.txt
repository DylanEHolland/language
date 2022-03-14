add_executable(test_memory
    Source/memory.test.cc
)

add_executable(test_address
    Source/address.test.cc
)

target_link_libraries(test_address common vm)
target_link_libraries(test_memory common vm)