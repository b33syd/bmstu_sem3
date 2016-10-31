cmake_minimum_required(VERSION 3.6)
project(Tisd3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Book.h Book.cpp Table_key.cpp.cpp)
add_executable(Tisd3 ${SOURCE_FILES})