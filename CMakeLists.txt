cmake_minimum_required(VERSION 3.13)
project(intersection)
set (CMAKE_CXX_STANDARD 11)

add_executable(intersection main_real.cpp CommonSequences.cpp helper.cpp runs_vs_alternate.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")