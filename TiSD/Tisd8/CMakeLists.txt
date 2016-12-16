cmake_minimum_required(VERSION 3.6)
project(Tisd8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp GraphShower.h)
add_executable(Tisd8 ${SOURCE_FILES})