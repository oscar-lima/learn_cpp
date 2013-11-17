cmake_minimum_required(VERSION 2.8.7)

project(using_external_library)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/script")

message("\nCMAKE_MODULE_PATH = ${CMAKE_MODULE_PATH}\n")

find_package(get_hello REQUIRED)

include_directories("${get_hello_INCLUDE_DIRS}")

add_executable(using_external_library src/using_external_library_tester.cpp)

target_link_libraries(using_external_library ${get_hello_LIBRARIES})