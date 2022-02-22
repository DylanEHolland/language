add_executable(lizas Source/main.cc)

add_library(assembler
    Include/parse_asm.h
    Source/parse_asm.cc
)

target_link_libraries(lizas common vm)