#!/usr/bin/env bash
# This is the entrypoint for docker containers
if [ "`basename $PWD`" != "liz" ]; then
    echo "[cd] /src/liz"
    cd /src/liz;
fi;

. Meta/Common.sh;

ARGS="";
BASH_ENVIRONMENT="
    HOME=$PWD
";
[ ! -z "$LIZ_CONTAINER" ] && BASH_ENVIRONMENT+="LIZ_CONTAINER=\"$LIZ_CONTAINER\"";
SCRIPT_TO_RUN=$1;
$IS_DOCKER && SCRIPT_TO_RUN=$3;
RUN_SCRIPT=true

$IS_DOCKER && [ ! -z "$3" ] && ARGS="${@:3}"
$IS_DOCKER || [ ! -z "$2" ] && ARGS="${@:2}"

[ ! -f $SCRIPT_TO_RUN ] && RUN_SCRIPT=false;
[ -z $SCRIPT_TO_RUN ] && RUN_SCRIPT=false;

if $RUN_SCRIPT; then
    FILE_BASE_NAME="`basename $SCRIPT_TO_RUN`";
fi;

$RUN_SCRIPT && if [ ! -z "$FILE_BASE_NAME" ] || [ $IS_DOCKER ]; then
    if [ -f "$SCRIPT_TO_RUN" ]; then
        echo "[docker]" $RUN_WITH $SCRIPT_TO_RUN;
        $IS_DOCKER || env -i $BASH_ENVIRONMENT bash -c "$SCRIPT_TO_RUN $ARGS";
        exit 0;
    fi;
fi;

$IS_DOCKER && env -i $BASH_ENVIRONMENT bash -c "${@}" && exit 0;
[ ! $IS_DOCKER ] && [ -z "$SCRIPT_TO_RUN" ] && echo "Dumping you to /bin/bash" && env -i $BASH_ENVIRONMENT bash && exit 0;
