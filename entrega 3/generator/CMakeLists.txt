cmake_minimum_required(VERSION 3.17)
project(generator)

set(CMAKE_CXX_STANDARD 14)

add_executable(generator main.cpp bezier.cpp bezier.h)