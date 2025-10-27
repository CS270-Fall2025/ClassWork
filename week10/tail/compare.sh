gcc -Wall *.c -o myTail
tail=$(tail test.txt)
myTail=$(./myTail test.txt)

if [[ $tail == $myTail ]]; then
    echo Your output match Linux tail
else
    echo Your output difrent from Linux tail
    diff <(echo $myTail) <(echo $tail)
fi
