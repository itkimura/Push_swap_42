#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft.h"

/*Delete later*/
# include <stdio.h>

typedef	struct		s_dlst
{
	int			*value;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}					t_dlst;

/* push_swap.h */
int	error(void);

/* validate_args.c */
int	validate_args(int ac, char **av);

/* init_numbers */
int	init_numbers(int ac, char **av, int **numbers, int *total);

/* init_stack */
int	init_stack(t_dlst **stack_a, t_dlst **stack_b, int *numbers, int total);
#endif
