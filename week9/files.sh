#!/bin/bash

echo 'Hello' > test1
echo 'Hello' > test2
echo 'Hi there' > test3

#if [ -e $1 ] && [ -e $2 ]; then
if test -e $1  && test -e $2 ; then  
    echo $1 and $2 exist
    if [[ $(diff $1 $2) ]]; then
        echo files are different
    else
        echo files are the same
    fi
else
    echo at least one of $1 and $2 does not exist
fi
