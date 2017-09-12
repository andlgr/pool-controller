# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.1.0)

# Project's name
project(pool-controller)

# Compiling options
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
add_compile_options(-g -std=c++11 -Wall -Wextra  -Wstrict-aliasing -pedantic -Werror -Wunreachable-code -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-promo -Wstrict-overflow=5 -Wswitch-default -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The App
include_directories("${PROJECT_SOURCE_DIR}/toplevel/include")

file(GLOB_RECURSE APP_SOURCES ${PROJECT_SOURCE_DIR}/toplevel/src/*.cc)

add_executable(pool-controller-app ${APP_SOURCES})
target_link_libraries(pool-controller-app Threads::Threads)

# The Test
include_directories("${PROJECT_SOURCE_DIR}/toplevel/test/")
include_directories("${PROJECT_SOURCE_DIR}/trd/gtest/googletest/include/")
include_directories("${PROJECT_SOURCE_DIR}/trd/gtest/googlemock/include/")

list(REMOVE_ITEM APP_SOURCES "${PROJECT_SOURCE_DIR}/toplevel/src/main.cc")
file(GLOB_RECURSE TEST_SOURCES ${PROJECT_SOURCE_DIR}/toplevel/test/*.cc)
file(GLOB_RECURSE TEST_LIBS ${PROJECT_SOURCE_DIR}/trd/gtest/build/*.a)

add_executable(pool-controller-test ${TEST_SOURCES} ${APP_SOURCES})
target_link_libraries(pool-controller-test Threads::Threads ${TEST_LIBS})
