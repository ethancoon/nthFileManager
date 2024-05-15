cmake_minimum_required(VERSION 3.26)

project(NthFileManager)

set(CMAKE_CXX_STANDARD 17)

add_executable(NthFileManager src/main.cpp
        lib/src/FileManager.cpp)