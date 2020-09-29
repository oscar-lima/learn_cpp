cmake_minimum_required(VERSION 2.8.3)
project(rosplan_dependencies)

# print all cmake variables
message(STATUS "================ALL VARIABLES (START) ==================")

# print all cmake variables : delete!
get_cmake_property(_variableNames VARIABLES)
list (SORT _variableNames)
foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()

message(STATUS "================ALL VARIABLES (END) ==================")
