#!/bin/bash
echo " what do you want "
read n
for i in $(ls)
do
    echo "$i"
    gedit $i
done
