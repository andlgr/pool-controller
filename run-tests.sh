#!/bin/sh

BIN='bin/*test'

valgrind --gen-suppressions=all --suppressions=custom.suppressions  --leak-check=full --show-reachable=yes --track-origins=yes $BIN

