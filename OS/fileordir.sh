echo "Enter name"
read f
if [ -f $f ]
then
echo "$f is a file"
fi
if [ -d $f ]
then
echo "$f is a directory"
fi