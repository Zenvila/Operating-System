#!/bin/bash
for var1 in 1 2 3
do
    for var2 in 0 5
    do
        if [ $var1 -eq 2 -a $var2 -eq 0 ]
        then
            continue
        else if [ $var1 -eq 4 -a $var2 -eq 1 ]
            then
                echo " $var1 "
            else
                echo " $var1 $var2 "
            fi
            fi
   done
done
