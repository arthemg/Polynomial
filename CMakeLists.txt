cmake_minimum_required(VERSION 3.6)
project(Polynomial)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp polynomial.cpp polynomial.h)
add_executable(Polynomial ${SOURCE_FILES})