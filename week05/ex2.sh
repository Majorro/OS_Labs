#!/bin/bash

FPATH='ex2.txt'
N='10'

for i in $( seq 1 $N )
do
    while ! ln "$FPATH" "$FPATH.lock"
    do
        sleep 1
    done

    num="$(("$(tail -n 1 $FPATH)"+1))"
    echo $num>>"$FPATH"

    rm "$FPATH.lock"
done