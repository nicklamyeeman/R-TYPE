#!/bin/bash

g++ -o Client client.cpp  -std=gnu++11 -pthread
mkdir build
cd build
conan install .. --build=missing
cmake ..
cmake -build .
