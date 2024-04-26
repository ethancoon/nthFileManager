cmake_minimum_required(VERSION 3.26)

project(NthFileManager)

set(CMAKE_CXX_STANDARD 17)

add_executable(NthFileManager FileManager/src/main.cpp
        FileManager/lib/src/FileManager.cpp)