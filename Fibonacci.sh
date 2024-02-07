echo "Enter a num"
read num
x=0
y=1
temp=0
if [ ${num} -ge 0 ]
then
for (( i = 0; i < num; i++ ))
 do
 temp=$(($x + $y))
 y=$x
 x=$temp
 echo "$temp"
done
else
echo "Try again!"
fi
