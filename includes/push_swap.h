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


/* validation.c */
int	error(void);
int	dublicate_check(int nb, t_dlst **curr);
int	is_valid_nb(char *str, int *i);
int	is_valid_str(char *str, t_dlst **curr);

/* init_stack */
t_dlst	*dlstnew(t_dlst *prev, int number);
int	init_dlst(t_dlst **stack_a, t_dlst **stack_b);
int	add_stack(char *str, t_dlst **curr);
void	free_stack(t_dlst **stack);
int	init_stack(int ac, char **av, t_dlst **stack_a);

/* operations.c */
int	swap(t_dlst *s);
int	push(t_dlst *a, t_dlst *b);
int	rotate(t_dlst *stack);
int	reverse(t_dlst *stack);

/* apply_operations.c */
//int	get_index(char *input);
int	apply_op(char *input, t_dlst *stack_a, t_dlst *stack_b);

/*Delete later print.c*/
void	print_detail(t_dlst *stack_a, t_dlst *stack_b);
void	print_stack(t_dlst *stack_a, t_dlst *stack_b);
#endif
