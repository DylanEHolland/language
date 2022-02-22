#!/usr/bin/env bash

. Meta/Common.sh;

echo "[Meta/Build.sh]";
sh Meta/Build.sh;# &> /dev/null || exit 1;
echo "Done.\n=\n\n"


RUN_ALL=false;
FAILURES=0

if [[ "$@" == "all" || "$@" == "" ]]; then
    RUN_ALL=true;
fi;

if $RUN_ALL; then
    echo "Test: Running all"
    N=1
    for test_cc_file in `find Tests -name "*.cc"`; do
        BASE_NAME="`basename $test_cc_file`";
        BASE_PATH=`echo $test_cc_file | sed -r "s/$BASE_NAME//" | sed 's/.$//'`;
        REGENED_PATH=`echo $BASE_PATH | sed -r "s/\/Source//"`;
        REGENED_FILE_NAME=test_`echo $BASE_NAME | sed -r 's/.cc//' | tr "." " " | awk '{$NF=""}1' | tr " " "_" | sed 's/.$//'`
        
        TEST_FILE_PATH="Build/$REGENED_PATH/$REGENED_FILE_NAME";
        if [ -f $TEST_FILE_PATH ]; then
            echo [Meta/Runtest.sh] "Found:" $TEST_FILE_PATH "($test_cc_file)";
            EXIT_CODE=`$TEST_FILE_PATH`
            $EXIT_CODE || FAILURES=$((FAILURES+1));
            $EXIT_CODE || echo "-> Failed!\n\n"
        else
            echo "[!NOEXISTS]" $TEST_FILE_PATH "(from: $test_cc_file)";
            exit 1;
        fi;

        N=$((N+1))
    done;
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

echo;
echo;
echo "---";
echo "Done.";
echo "Number of failures:" $FAILURES;

exit $FAILURES;