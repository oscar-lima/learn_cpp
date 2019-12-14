cmake_minimum_required(VERSION 2.8)

project(containers)

# compile with c++ 11
add_compile_options(-std=c++11)

add_executable(std_vector src/std_vector.cpp)
