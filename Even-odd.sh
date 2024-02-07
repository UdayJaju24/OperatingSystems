echo "Enter num"
read num
echo "Your num is $num"
if [ `expr $num % 2` == 0 ];
then
 echo "Even"
else
 echo "Odd"
fi
