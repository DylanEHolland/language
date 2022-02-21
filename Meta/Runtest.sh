#!/usr/bin/env bash

. Meta/Common.sh;

sh Meta/Build.sh &> /dev/null || echo "Building failed. Dying" && exit 1;

RUN_ALL=false;
FAILURES=0

if [[ "$@" == "all" || "$@" == "" ]]; then
    RUN_ALL=true;
fi;

if $RUN_ALL; then
    echo "Running all"
else
    N=1
    for f in $@; do
        echo "Test #$N: Build/Tests/$@"
        EXIT_CODE=`Build/Tests/"$@"`;
        N=$((N+1))
        $EXIT_CODE && echo passed || FAILURES=$((FAILURES+1));
        echo;
    done;
fi;

echo "===";
echo;
echo "Done.";
echo "Number of failures:" $FAILURES;