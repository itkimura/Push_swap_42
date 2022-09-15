if [ $# == 3 ]
then
    min=$2
    max=$3
else
	min=-2147483648
	max=2147483647
fi
nb=`jot -r $1 $min $max | sort | uniq | tr '\n' ' '`
echo $nb
./push_swap $nb | ./checker $nb
#seq $1 $2 | shuf | tr '\n' ' '
