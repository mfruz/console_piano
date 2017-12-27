cmake_minimum_required(VERSION 3.8)
project(piano)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp include/Note.cpp include/Note.hpp include/Piano.cpp include/Piano.hpp include/Keyboard.cpp include/Keyboard.hpp include/Song.cpp include/Song.hpp include/Silence.cpp include/Silence.hpp include/FileManager.cpp include/FileManager.hpp)
add_executable(piano ${SOURCE_FILES} include/Keyboard.cpp include/Keyboard.hpp include/Song.cpp include/Song.hpp include/Silence.cpp include/Silence.hpp)