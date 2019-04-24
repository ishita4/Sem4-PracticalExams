echo "Enter number"
read num
i=1
while [ $i -le 10 ]
do
temp=$((num*i))
echo "$num x $i = $temp"
i=$((i+1))
done