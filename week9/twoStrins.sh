#!/bin/bash
read -p "Enter the first string " str1
read -p "Enter the second string " str2

if [[ "$str1" == "$str2" ]]; then
#if [ "$str1" = "$str2" ]; then
# if test $str1 = $str2 ; then
    echo strings are the same
else
    echo strings are different
fi
