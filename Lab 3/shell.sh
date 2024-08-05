echo "Enter 2 val"

#to read a and b
read a b

#to display the read values
echo $a $b

#expr used for arithmetic operations
a=$(expr $a + 1)
echo $a

#[] is used as condition, stores 1 if true and 0 if false
result=$[a==b]
#echo "The values of a and are $result"

if (( $result==1));then
	echo "The values of a and b are equal"
else
	echo "The values of a and b are not equal"
fi
