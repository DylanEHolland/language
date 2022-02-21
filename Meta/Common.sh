#!/usr/bin/env bash

export IS_DARWIN=`[ "$(uname)" = "Darwin" ]`

if [ $IS_DARWIN ]; then
    NUM_CORES=`sysctl -n hw.ncpu`;
else
    NUM_CORES=`grep processor /proc/cpuinfo | wc -l`;
fi;
