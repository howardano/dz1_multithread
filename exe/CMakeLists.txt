project(main_)

set(EXE_SOURCES main.cpp)
add_executable(main ${EXE_SOURCES})
set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
target_include_directories(main PUBLIC ${CMAKE_SOURCE_DIR}/include)