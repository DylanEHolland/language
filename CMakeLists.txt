cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
project(liz)

add_subdirectory(Source)
add_subdirectory(Tests)

target_include_directories(
    common
    PUBLIC
        "Source"
)

target_include_directories(
    vm
    PUBLIC
        "Source"
)

target_include_directories(
    data_types
    PUBLIC
        "Source"
)

target_include_directories(
    memory
    PUBLIC
        "Source"
)