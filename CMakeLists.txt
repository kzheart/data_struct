cmake_minimum_required(VERSION 3.21)
project(data_struct)

set(CMAKE_CXX_STANDARD 11)

add_executable(data_struct main.cpp)
add_subdirectory(LinearList)
add_subdirectory(Stack)
add_subdirectory(Tree)
add_subdirectory(Search/ZheBan)
add_subdirectory(Sort)
add_subdirectory(Chapter2)
add_subdirectory(Chapter3)