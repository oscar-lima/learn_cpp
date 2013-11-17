cmake_minimum_required(VERSION 2.8.7)

project(building_a_library)

#include_directories("${CMAKE_SOURCE_DIR}/include")
include_directories("./include")

add_library(get_hello include/get_hello.cpp include/get_hello.h)

add_executable(building_a_library_2 src/library_tester.cpp)

target_link_libraries(building_a_library_2 get_hello)