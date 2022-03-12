cmake_minimum_required(VERSION 3.13)
project(intersection)
set (CMAKE_CXX_STANDARD 11)

add_executable(intersection main_compare_heuristics.cpp CommonSequences.cpp Algorithms.cpp helper.cpp test_heuristics.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")