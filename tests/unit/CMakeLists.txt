cmake_minimum_required(VERSION 3.16)
project(test_realisation)

set(CMAKE_CXX_STANDARD 11)
set(EXE_SOURCES tests.cpp)

message("PROJECT_NAME IN TEST = ${PROJECT_NAME}")
find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} ${EXE_SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} GTest::gtest_main)