#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

int main(int ac, char **av)
{
	char str[] = "python3 helloworld.py ";
	char *res;
	res = ft_strjoin(str, av[1]);
	system(res);
}
