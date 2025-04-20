#!/bin/bash
num="1 2 3 4 5 6 7 8"
for n in $num
do
   q=`expr $n % 2`
   if [ $q -eq 0 ]
   then
      echo "$n even no"
      continue
   fi
   echo "$n odd no"
done

