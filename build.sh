#!/bin/sh

# Build Google Test framework
cd trd/gtest/
cmake -H. -Bbuild
cmake --build build -- -j4
cd ../../

# Build Pool Controller Application
cmake -H. -Bbuild
cmake --build build -- -j4

