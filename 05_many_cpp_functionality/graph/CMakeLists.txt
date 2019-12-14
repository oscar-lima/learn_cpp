cmake_minimum_required(VERSION 2.8)

project(esterel_plan)

add_compile_options(-std=c++11)

include_directories(include)

add_executable(esterel_plan src/esterel_plan.cpp)

add_executable(floyd_warshall src/floyd_warshall.cpp)
