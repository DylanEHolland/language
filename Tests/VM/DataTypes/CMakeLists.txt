add_executable(test_atom
    atom.test.cc
)

add_executable(test_nil
    nil.test.cc
)

add_executable(test_number
    number.test.cc
)

target_link_libraries(test_atom common vm data_types)
target_link_libraries(test_nil common vm data_types)
target_link_libraries(test_number common vm data_types)
