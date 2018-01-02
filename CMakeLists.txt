cmake_minimum_required(VERSION 3.8)
project(piano)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/Note.cpp include/Note.hpp src/Piano.cpp include/Piano.hpp src/Keyboard.cpp include/Keyboard.hpp src/Song.cpp include/Song.hpp src/FileManager.cpp include/FileManager.hpp src/Rest.cpp include/Rest.hpp)
add_executable(piano ${SOURCE_FILES} src/Keyboard.cpp include/Keyboard.hpp src/Song.cpp include/Song.hpp)