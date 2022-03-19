add_subdirectory(VM)
add_subdirectory(Tools)

add_executable(test_initial_vm
    Source/initial_vm.test.cc
)

target_link_libraries(test_initial_vm common vm assembly)