#!/usr/bin/env bash

IS_DARWIN=false;
if [ $(uname) = "Darwin" ]; then
    IS_DARWIN=true;
fi;
export IS_DARWIN;

if $IS_DARWIN; then
    NUM_CORES=`sysctl -n hw.ncpu`;
else
    NUM_CORES=`grep processor /proc/cpuinfo | wc -l`;
fi;
