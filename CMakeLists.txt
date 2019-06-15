cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 11)

file(GLOB src *.cpp)
add_executable(CM ${src})
configure_file(test.c test.c COPYONLY)