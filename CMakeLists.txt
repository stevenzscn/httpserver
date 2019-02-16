cmake_minimum_required(VERSION 2.8)

project(httpserver)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall ${CMAKE_CXX_FLAGS}")
add_subdirectory(src)
