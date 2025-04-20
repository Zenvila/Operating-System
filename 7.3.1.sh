#!/ bin/ bash
echo " enter the a value "
read a
echo " enter the b value "
read b
c=` expr $a + $b `
echo " sum: $c"
c=` expr $a - $b `
echo " sub: $c"
c=` expr $a \* $b `
echo " mul: $c"
c=` expr $a / $b `
echo " div: $c"
