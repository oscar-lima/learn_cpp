cmake_minimum_required(VERSION 2.8.7)

project(adding_simple_library)

include_directories("${CMAKE_SOURCE_DIR}/include")
message ( "\n\nvariable CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}\n\n")
add_executable(adding_simple_library src/adding_simple_library.cpp)