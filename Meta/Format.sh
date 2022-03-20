#!/usr/bin/env bash

append_newline() {
    if ! [[ -s "$1" && -z "$(tail -c 1 "$1")" ]]
    then
        echo >> $1;
    fi
}

OUR_FILES=`find ./ -name '.git' -type d -prune -o -print | grep -v ".//Build"`

for our_file in $OUR_FILES; do
    if [ ! -d $our_file ]; then
        append_newline $our_file;
    fi;
done;
