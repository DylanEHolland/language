#!/usr/bin/env bash

. meta/common.sh;

if [ ! -d Build ]; then
    mkdir Build;
fi;

cd Build && \
cmake .. && \
cd - && \
make -j$NUM_CORES -C Build;