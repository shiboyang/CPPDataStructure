cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include_directories(struct)

project(CPPDataStructure VERSION 1.0)

add_executable(Main main.cpp
        struct/vector.cpp
        struct/queue.cpp)

