if [ $# = 0 ]; then
    echo "Provide number of lines"
    exit
fi

if [ -e "test.txt" ]; then
    rm test.txt
fi

num=1
while [ $num -le $1 ]
do
    echo "Line $num" >> test.txt
    (( num++ ))
done