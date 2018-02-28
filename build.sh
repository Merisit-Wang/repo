#!/bin/bash

if [ ! -d "cmake-build" ]; then
    mkdir -p cmake-build
fi

cd cmake-build
cmake ..
make -j20

cd test
./repo-test
