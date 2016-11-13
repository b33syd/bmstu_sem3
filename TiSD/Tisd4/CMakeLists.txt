cmake_minimum_required(VERSION 3.6)
project(Tisd4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Q_array.cpp Q_array.h lib.h Q_list.cpp Q_list.h)
add_executable(Tisd4 ${SOURCE_FILES})