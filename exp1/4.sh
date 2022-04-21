#! /bin/bash

echo "Enter a number: "
read c
i=1
x=$c

while [ $i -le $c ]
do
  if( ( $x % $i ) -eq 0 )
     then
     echo $i
     fi    
  (($i++))
done

