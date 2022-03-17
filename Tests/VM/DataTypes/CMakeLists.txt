add_executable(test_base_type
    base_type.test.cc
)

add_executable(test_number
    number.test.cc
)

target_link_libraries(test_base_type common vm data_types)
target_link_libraries(test_number common vm data_types)