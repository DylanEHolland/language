add_executable(lizas 
    Include/parse_asm.h    
    
    Source/main.cc
    Source/parse_asm.cc
)

target_link_libraries(lizas common vm)