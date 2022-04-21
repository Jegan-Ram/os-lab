#! /bin/bash
echo -n "enter string : "
read str
v=$(echo $str | grep -o -i "[aeiou]" | wc -l)
echo $v
