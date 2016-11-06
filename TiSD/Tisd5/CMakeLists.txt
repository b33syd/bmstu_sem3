cmake_minimum_required(VERSION 3.6)
project(Tisd5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp NormalMatrix.cpp NormalMatrix.h SparseMatrix.cpp SparseMatrix.h)
add_executable(Tisd5 ${SOURCE_FILES})