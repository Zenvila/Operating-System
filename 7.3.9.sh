#!/bin/bash
ch='y'
while [ $ch = 'y' ]
do
    echo " enter your choice "
    echo " 1. number of users logged on "
    echo " 2. print calendar "
    echo " 3. print date "
    read d
    case $d in
        1) who;;
        2) cal 20;;
        3) date;;
        *) break;;
    esac
    echo " do you wish to continue ( y / n ) "
    read ch
done
