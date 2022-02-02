cmake_minimum_required(VERSION 3.20)
project(basicsOfProgramming2 C)

set(CMAKE_C_STANDARD 11)

add_executable(basicsOfProgramming2 main.c)

add_subdirectory(libs)
target_link_libraries(basicsOfProgramming2 algorithms)
target_link_libraries(basicsOfProgramming2 data_structures)

