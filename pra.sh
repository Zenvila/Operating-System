echo "enter the value:" 
read a 
echo "enter the value :"
read b 

c=$(expr "$a" + "$b" )
echo "sum : $c"

c=$(expr "$a" - "$b" )
echo "sub : $c"


c=$(expr "$a" \* "$b" )
echo "Mul : $c"


c=$(expr "$a" / "$b" )
echo "div : $c"


c=$(expr "$a" % "$b" )
echo "Mod : $c"
