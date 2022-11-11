#!/bin/bash

make clean
make
./TicTacToeBoardTest
gcov TicTacToeBoardTest.cpp