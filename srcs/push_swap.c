#include "push_swap.h"

/*
 * Insid of mail function:
 * return (0) = successfully
 * return (1) = Error
 * 
*/

int main(int ac, char **av)
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;
	int		*list;

	stack_a = NULL;
	stack_b = NULL;
	list = NULL;
	if (!validate_args(ac, av))
	{
		ft_putstr("ERROR\n");
		return (1);
	}
	else
	{
		ft_putstr("OK\n");
		return (0);
	}
}
