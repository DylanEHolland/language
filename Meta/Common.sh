#!/usr/bin/env bash

export PATH="/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/opt/homebrew/bin:/opt/homebrew/opt/texinfo/bin";

IS_DARWIN=false;
IS_DOCKER=false

[ ! -z "$LIZ_CONTAINER" ] && IS_DOCKER=true;
if [ $(uname) = "Darwin" ]; then
    IS_DARWIN=true;
fi;

if $IS_DARWIN; then
    NUM_CORES=`sysctl -n hw.ncpu`;
else
    NUM_CORES=`grep processor /proc/cpuinfo | wc -l`;
fi;

export IS_DARWIN;
export IS_DOCKER;
export NUM_CORES;
