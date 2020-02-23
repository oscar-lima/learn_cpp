cmake_minimum_required(VERSION 2.8.7)

project(graph_search)

add_compile_options(-std=c++11)

include_directories(include)

add_library(graph src/graph.cpp)

add_executable(bfs src/bfs.cpp)

target_link_libraries(bfs graph)
