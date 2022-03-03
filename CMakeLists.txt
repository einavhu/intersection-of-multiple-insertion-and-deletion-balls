cmake_minimum_required(VERSION 3.13)
project(intersection)
set (CMAKE_CXX_STANDARD 11)

add_executable(intersection main.cpp CommonSequences.cpp trivial_1.cpp trivial_2.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")