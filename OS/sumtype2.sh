i=51
while [ $i -le 100 ]
do
temp1=$((i%5))
temp2=$((i%3))
if [[ temp1 -ne 0 && temp2 -eq 0 ]]
then
s=$((s+i))
fi
i=$((i+1))
done
echo "Sum is = $s"
