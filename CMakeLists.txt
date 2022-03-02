cmake_minimum_required(VERSION 3.13)
project(intersection)
set (CMAKE_CXX_STANDARD 11)

add_executable(intersection CommonSequences.cpp main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")