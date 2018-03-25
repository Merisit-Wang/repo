#!/bin/bash

arg=$1

if [ ! -d "cmake-build" ]; then
    mkdir -p cmake-build
fi

cd cmake-build

if [ "$arg" == "install" ]; then
    echo "build install"
    rm -rf *
    cmake ..
else
    echo "build test"
    rm -rf src/test/repo-test
    cmake .. -DENABLE_TEST=1
fi

make -j20

if [ "$arg" == "install" ]; then
    sudo cp src/repo /usr/local/bin 
else
    cd src/test
    ./repo-test
fi
