cmake_minimum_required(VERSION 3.3)

project(shine CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src bin)
add_subdirectory(tests tests)
