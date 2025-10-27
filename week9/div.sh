#!/bin/bash

declare -i testval=20
declare -i count=2                    # start at 2, 1 always works

while (( $count <= $testval )); do
    (( result = $testval % $count ))
    if (( $result == 0 )); then       # evenly divisible
        echo " $testval is evenly divisible by $count"
    fi
    (( count++ ))
done
