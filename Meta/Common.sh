#!/usr/bin/env bash

export IS_DARWIN=`[[ `uname` == "Linux" ]] && exit 0 || exit 1`
if $IS_DARWIN; then
    NUM_CORES=`sysctl -n hw.ncpu`;
else
    NUM_CORES=`grep processor /proc/cpuinfo | wc -l`;
fi;
