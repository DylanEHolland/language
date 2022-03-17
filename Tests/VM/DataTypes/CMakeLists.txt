add_executable(test_number
    number.test.cc
)

target_link_libraries(test_number common vm data_types)