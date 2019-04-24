echo "Enter number"
read num
s=0
i=0
while [ $i -le $num ]
do
s=$((s+i))
i=$((i+1))
done
echo "Sum is = $s"
