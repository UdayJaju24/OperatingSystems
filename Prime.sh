echo "Enter a num"
read num
count=0
for (( i = 1; i < $(($num/2)); i++ ))
 do
 if [ `expr $num % $i` == 0 ];
 then
 count=$(($count + 1))
 fi
done
if [ $count -ge 0 ]
then
 echo "Non Prime"
else 
 echo "Prime"
fi
echo "$x
