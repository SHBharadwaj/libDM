cmake_minimum_required(VERSION 3.10)

# set project name 
project(DM)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

SET( CMAKE_CXX_FLAGS " -std=c++11 -Wunused -Wall -Wno-null-conversion") 

include_directories(${CMAKE_CURRENT_SOURCE_DIR} include/)

add_subdirectory(lib)
add_subdirectory(tools)

