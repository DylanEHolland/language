add_executable(lizvm
    Source/main.cc
)

target_link_libraries(lizvm common vm)