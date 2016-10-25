cmake_minimum_required(VERSION 3.6)
project(Tisd2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp stackarray.cpp stacklist.cpp)
add_executable(Tisd2 ${SOURCE_FILES})