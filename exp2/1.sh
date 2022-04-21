#! /bin/bash

echo "Enter username:"
read name

id -gn > users.txt

while read line
do
   if [ "$line" = "$name"  ]
   then
     echo "Same User"   
   else
     echo "different user" 
   fi
done < users.txt

