echo "Enter a num"
read num
x=1
for (( i = 1; i < num; i++ ))
 do
 x=$(($x * $i))
done
echo "$x"
