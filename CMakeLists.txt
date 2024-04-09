cmake_minimum_required(VERSION 3.27)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 20)

set(wxBUILD_SHARED OFF)
add_subdirectory("libs/wxWidgets-3.2.4")

add_executable(GameOfLife src/main.cpp
        src/Biotope.cpp
        src/Biotope.h)
