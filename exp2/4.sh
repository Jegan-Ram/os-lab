#! /bin/bash

ls -al > info.txt
while read line
do
    size=$(cut -d" " -f 5 <<<$line)
    name=$(cut -d" " -f 9 <<<$line)
    echo $size >> size.txt
    echo $name >> name.txt   
done < info.txt
max=0
i=0
while read line
do
  if [ $line > $max ]
  then
      max=$line
      (( i++ ))
  fi     
done < size.txt
cat name.txt | head -$i | tail -1
echo "$max is the max file size"
