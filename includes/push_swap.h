#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft.h"

/*Delete later*/
# include <stdio.h>

typedef	struct		s_dlst
{
	int				value;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}					t_dlst;

/* push_swap.h */
int	error(void);

/* validation.c */
int	is_valid_nb(char *str, int *i);
int	is_valid_str(char *str, t_dlst **curr, int *count);

/* init_stack */
t_dlst	*dlstnew(t_dlst *prev, int number);
int	add_stack(char *str, t_dlst **curr, int *count);
int	init_stack(int ac, char **av, t_dlst **stack_a, int *total);

/* commands_a.c */
int	sa(t_dlst *s);
int	pa(t_dlst *a, t_dlst *b);

/* commands_b.c */
int	sb(t_dlst *s);
int	pb(t_dlst *a, t_dlst *b);

/*Delete later print.c*/
void	print_detail(t_dlst *stack_a, t_dlst *stack_b);
void	print_stack(t_dlst *stack_a, t_dlst *stack_b, int total);
#endif
