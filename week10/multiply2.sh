#!/bin/bash

# two-parameter function
multiply ()
{   
    (( product = $1 * $2 ))
    echo $product    # echo product to standard output
}

num1=3
num2=4
result=$(multiply $num1 $num2)        # get the exit code
echo "Product of $num1 and $num2 is $result"
