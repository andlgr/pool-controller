#!/bin/sh

# Build Google Test framework
echo "# Building Google Test framework"
cd trd/gtest/
cmake -H. -Bbuild
cmake --build build -- -j4
cd ../../

echo "# Building Pool Controller"
# Build Pool Controller Application
cmake -H. -Bbuild
cmake --build build -- -j4

