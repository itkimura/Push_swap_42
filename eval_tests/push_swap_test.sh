RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
BOLD='\033[0;1m'
NC='\033[0m'

times=200
ac=$#
flag=0
detail=0
if [ $ac -eq 0 -o "$1" = "--help" ]; then
	echo -e "Discription:\n"
	echo -e "  The scrip tests push_swap with random numbers between ${BOLD}INT_MIN${NC} and ${BOLD}INT_MAX${NC} for ${BOLD}200${NC} times as default\n"
	echo -e "Basic usage:\n"
	echo -e "  ${BOLD}bash push_swap_test.sh [the number of random numebers] optional:[lowest] optional:[heighet]${NC}\n"
	echo -e "The following option is available:\n"
	echo -e "  ${BOLD}bash push_swap_test.sh${NC}\t\t\tprint this help message"
	echo -e "  ${BOLD}bash push_swap_test.sh --help${NC}\t\t\tprint this help message"
	echo -e "  ${BOLD}bash push_swap_test.sh 10${NC}\t\t\ttest push_swap with ${BOLD}10${NC} random numbers between ${BOLD}INT_MIN${NC} and ${BOLD}INT_MAX${NC} for ${BOLD}200${NC} times (range INT_MIN to INT_MAX and 200 times is default)"
	echo -e "  ${BOLD}bash push_swap_test.sh 10 1 10${NC}\t\ttest push_swap with ${BOLD}10${NC} random numbers between ${BOLD}1${NC} and ${BOLD}100${NC} for 200 times\n"
	echo -e "  ${BOLD}bash push_swap_test.sh 10 -t 10${NC}\t\ttest push_swap with ${BOLD}10${NC} random numbers ${BOLD}10${NC} times${NC}"
	echo -e "  ${BOLD}bash push_swap_test.sh 10 -d${NC}\t\t\ttest push_swap with ${BOLD}10${NC} random numbers with ${BOLD}details${NC}\n"
	exit
fi
# flag check
for arg in "$@"; do
	if [ "$arg" = "-t" ]; then
		flag=1
	else
		if [ $flag -eq 1 ]; then
			times=$arg
			flag=0
			ac=$((ac-2))
		fi
	fi
	if [ "$arg" = "-d" ]; then
		detail=1
		ac=$((ac-1))
	fi
done


if [ $ac == 3 ]
then
    min=$2
    max=$3
#	random=`seq $min $max | shuf| head -n $1 | tr '\n' ' '`
else
	min=-2147483648
	max=2147483647
#	random=`jot -r $1 $min $max | sort | uniq | tr '\n' ' '`
fi

min_res=2147483647
max_res=0
ave=0
echo -e "[itkimura push_swap tester]"
echo -e "Test ${BOLD}$times${NC} times: ${BOLD}$1${NC} numbers${BOLD}${NC} between ${BOLD}$min${NC} and ${BOLD}$max${NC}"
for (( i=0 ; "$i" < "$times" ; i++ )); do
	if [ $ac -eq 3 ]; then
		random=`seq $min $max | sort -R | head -n $1 | tr '\n' ' '`
	else
		nb=0
		while [ $nb -ne $1 ]; do
			random=`jot -r $1 $min $max | sort -R | uniq`
			nb=`echo $random|grep -o ' '|wc -l`
			nb=$((nb+1))
		done
		random=`echo $random| tr '\n' ' '`
	fi
	res=`./push_swap $random | ./checker $random`
	res_nb=`./push_swap $random | wc -l | tr -d ' '`
	ave=$((ave + res_nb))
	if [ $res_nb -lt $min_res ]; then
		min_res=$res_nb
	fi
	if [ $res_nb -gt $max_res ]; then
		max_res=$res_nb
	fi
	if [ $detail -eq 0 ]; then
		if [ $res='OK\n' ]; then
			echo -e -n "${GREEN}.${NC}"
		else
			echo -e -n "${RED}F${NC}"
		fi
	else
		if [ $res='OK\n' ]; then
			echo -e "[${GREEN}OK${NC}] $random"
		else
			echo -e "[${RED}KO${NC}] $random"
		fi

	fi
done
	ave=$((ave/$times))
	echo ""
	echo -e "max:\t$max_res"
	echo -e "ave:\t$ave"
	echo -e "min:\t$min_res"
#./push_swap $random | ./checker $random
