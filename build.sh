#!/bin/sh

# Build Google Test framework
echo "# Building Google Test framework"
cd trd/gtest/
cmake -H. -Bbuild
cmake --build build -- -j4
cd ../../

# Build Pool Controller Application
echo "# Building Pool Controller"
cmake -H. -Bbuild
cmake --build build -- -j4

