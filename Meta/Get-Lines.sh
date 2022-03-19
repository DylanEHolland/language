#!/usr/bin/env bash

for fp in $(echo `find . -name "*.cc"` `find . -name "*.h"`); do
    cat $fp;
done | wc -l | awk '{print $1}';