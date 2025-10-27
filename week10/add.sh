#! /bin/bash
#1.	Create a script that adds all elements if the list 
#numbers=(1 2 3 4 5 6 7 8 9)

#numbers=(1 2 3 4 5 6 7 8 9)
# echo $@
add()
{
    sum=0
    for n in $@
    do
        (( sum = sum + n ))
    done
    echo "Average = " $(echo "scale=2; $sum / $#" | bc)
}
numbers=(1 2 3 4 5 6 7 8 9)
echo "$(add ${numbers[*]})"





# sum=0
# for n in ${numbers[@]}
# do
#     (( sum = sum + $n ))
# done
# echo $sum
