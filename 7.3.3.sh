#!/bin/bash
echo " which table you want "
read n
for i in 1 2 3 4 5 6 7 8 9 10
do
    echo "$i * $n = ` expr $i \* $n`"
done
