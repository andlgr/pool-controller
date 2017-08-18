# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.9.1)

# Project's name
project(pool-controller)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}/toplevel/include")

# Source files
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/toplevel/src/*.cc ${PROJECT_SOURCE_DIR}/toplevel/src/*.cpp)

# The App
add_executable(pool-controller-app ${SOURCES})

