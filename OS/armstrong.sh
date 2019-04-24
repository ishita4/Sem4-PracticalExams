echo "Enter number"
read num
a=0
b=1
i=0
echo -n "$a "
echo -n "$b " 
temp=$((num-2))
while [ $i -lt $temp ]
do
c=$((a+b))
echo -n "$c "
a=$b
b=$c
i=$((i+1))
done