#! /bin/bash
n=10
declare -a nums
for i in {0..9} 
   do
   echo "Enter $i element"
   read nums[$i]
   done
sum=0  
for i in ${nums[@]}
do
    sum=`expr $sum + $i`
done
 echo "sum= $sum"
 avg=`echo $sum / $n | bc -l`
 echo "average= $avg"
