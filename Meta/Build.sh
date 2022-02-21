#!/usr/bin/env bash

. Meta/Common.sh;

if [ ! -d Build ]; then
    mkdir Build;
fi;

cd Build && \
cmake .. && \
cd - && \
make -j$NUM_CORES -C Build;


if [ ! -d Build/bin ]; then
    mkdir Build/bin;
    for exe in lizas lizvm; do 
        cp -v Build/Source/Tools/$exe/$exe Build/bin;
    done;
fi;
