cmake_minimum_required(VERSION 3.8)
project(TreeEncrypter)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/main.cpp
        src/avl.cpp
        src/avl.hpp
        src/rbt.cpp
        src/rbt.hpp
        src/utils.cpp
        src/utils.hpp
        src/pile.cpp
        src/pile.hpp)
add_executable(TreeEncrypter ${SOURCE_FILES})
