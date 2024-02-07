num=(1 5 8 2 4)
temp=0
for ((i = 0; i<5; i++))
do
 for((j = 0; j<5-i-1; j++))
 do
 if [ ${num[j]} -gt ${num[$((j+1))]} ]
 then
 temp=${num[j]}
 num[$j]=${num[$((j+1))]} 
 num[$((j+1))]=$temp
 fi
 done
done
echo "${num[@]}"
