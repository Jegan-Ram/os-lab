#! /bin/bash

echo "enter file path"
read pat
if ls -al $pat | grep -q "x"; then
echo "Executable file"
else
echo "Non-Executable file"
fi


