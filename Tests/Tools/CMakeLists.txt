add_executable(test_parse_instructions
    Source/parse_instructions.test.cc
)

target_link_libraries(test_parse_instructions common vm assembly)