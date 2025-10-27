#!/bin/bash

# two-parameter function
multiply ()
{
    (( product = $1 * $2 ))
    return $product
}

num1=3
num2=4
multiply $num1 $num2
result=$?        # get the exit code
echo "Product of $num1 and $num2 is $result"
