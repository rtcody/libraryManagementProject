cmake_minimum_required(VERSION 3.27)
project(libraryProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(libraryProject
        src/Book.cpp
        src/Book.h
        src/User.h
        src/User.cpp
        src/main.cpp)
