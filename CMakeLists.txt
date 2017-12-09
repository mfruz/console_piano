cmake_minimum_required(VERSION 3.8)
project(piano)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp include/Keyboard.cpp include/Keyboard.hpp include/Note.cpp include/Note.hpp)
add_executable(piano ${SOURCE_FILES})