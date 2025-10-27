#!/bin/bash

name=Ekaterina
#print the third letter
result=$(( ${#name} - 1 ))
echo $result
echo ${name:$(( ${#name} - 1 )):1} #${var:offset:lenght}
#TODO
#print "kate"

#Print the last letter Hint: use the length of the word
