cmake_minimum_required(VERSION 3.13)
project(workbench)

set(CMAKE_CXX_STANDARD 17)

add_executable(workbench main.cpp algorithms/hanoitower.cpp algorithms/hanoitower.h algorithms/mergesort.cpp algorithms/mergesort.h main.h containers/vector.cpp containers/vector.h)