#!/bin/bash

declare -i testval=100
declare -i count=1                    # start at 2, 1 always works

while (( $count <= $testval )); do
    echo "Line $count" >>test.txt
    (( count++ ))
done
