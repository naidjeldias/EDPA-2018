cmake_minimum_required(VERSION 3.8)
project(AVL)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/main.cpp
        src/avl.cpp
        src/avl.hpp
        src/rbt.cpp
        src/rbt.hpp
        src/utils.cpp
        src/utils.hpp)
add_executable(AVL ${SOURCE_FILES})