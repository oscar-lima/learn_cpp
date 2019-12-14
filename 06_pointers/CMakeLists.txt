cmake_minimum_required(VERSION 2.8.7)

add_compile_options(-std=c++14)

project(pointers)

add_executable(pointers1 src/pointers1.cpp)
add_executable(smart_pointer src/smart_pointer.cpp)
add_executable(function_pointers src/function_pointers.cpp)

# callback example using function pointers
include_directories(include)
add_library(prog2 src/prog2.cpp)
add_executable(prog1 src/prog1.cpp)
target_link_libraries(prog1 prog2)
