# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.0)

# Project's name
project(pool-controller)

# Compiling options
add_compile_options(-std=c++11 -Wall -Werror -g)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The App
include_directories("${PROJECT_SOURCE_DIR}/toplevel/include")

file(GLOB_RECURSE APP_SOURCES ${PROJECT_SOURCE_DIR}/toplevel/src/*.cc)

add_executable(pool-controller-app ${APP_SOURCES})

# The Test
include_directories("${PROJECT_SOURCE_DIR}/toplevel/test/")
include_directories("${PROJECT_SOURCE_DIR}/trd/gtest/googletest/include/")
include_directories("${PROJECT_SOURCE_DIR}/trd/gtest/googlemock/include/")

list(REMOVE_ITEM APP_SOURCES "${PROJECT_SOURCE_DIR}/toplevel/src/main.cc")
file(GLOB_RECURSE TEST_SOURCES ${PROJECT_SOURCE_DIR}/toplevel/test/*.cc)
file(GLOB_RECURSE TEST_LIBS ${PROJECT_SOURCE_DIR}/trd/gtest/build/*.a)

add_executable(pool-controller-test ${TEST_SOURCES} ${APP_SOURCES})
target_link_libraries(pool-controller-test ${TEST_LIBS})
