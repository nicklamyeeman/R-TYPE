#!/bin/bash

mkdir build
cd build
conan install .. --build=missing
cmake ..
cmake -build .
make
./bin/r-type_client