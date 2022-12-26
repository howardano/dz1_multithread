cmake_minimum_required(VERSION 3.16)

project(dz1)
message("PROJECT_NAME = ${PROJECT_NAME}")
message(STATUS ${CMAKE_BINARY_DIR})
add_subdirectory(exe/)
add_subdirectory(tests/unit)