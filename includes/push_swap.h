#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "libft.h"
# define SORTLIMIT 30

/*Delete later*/
# include <stdio.h>

typedef	struct		s_dlst
{
	int				value;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}					t_dlst;

typedef	struct	s_sort
{
	int			max;
	int			prev;
	int		tmp[SORTLIMIT + 10];
	int		ans[SORTLIMIT + 10];
}				t_sort;

enum ops{
	sa, //0
	sb, //1
	ss, //2
	pa, //3
	pb, //4
	ra, //5
	rb, //6
	rr, //7
	rra,//8
	rrb, //9
	rrr //10
};

/* validation.c */
void	error(void);
int	dublicate_check(int nb, t_dlst **curr);
int	is_valid_nb(char *str, int *i);
int	is_valid_str(char *str, t_dlst **curr, int *total);

/* init_stack */
t_dlst	*dlstnew(t_dlst *prev, int number);
int	init_dlst(t_dlst **stack_a, t_dlst **stack_b);
int	add_stack(char *str, t_dlst **curr, int *total);
void	free_stack(t_dlst **stack);
int	init_stack(int ac, char **av, t_dlst **stack_a, int *total);

/* operations.c */
int	swap(t_dlst *s);
int	push(t_dlst *a, t_dlst *b);
int	rotate(t_dlst *stack);
int	reverse(t_dlst *stack);

/* apply_operations.c */
bool	avoid_check(int ops, t_sort *t);
int	get_index(char *input);
bool	sort_dlst(t_dlst *stack_a, t_dlst *stack_b, int index, bool recover);
int	recover_dlst(t_dlst *stack_a, t_dlst *stack_b, int index);
int	apply_op(int index, t_dlst *stack_a, t_dlst *stack_b);

/* small_sort.c */
int	small_sort(t_dlst *a, t_dlst *b, int total);
void	dfs(t_dlst *stack_a, t_dlst *stack_b, t_sort *t, int turn);

/* checker.c */
int	is_sorted(t_dlst *a, t_dlst *b);

/* push_answer.c */
void	print_operations(int index);
void print_ans(t_sort *t);

/*Delete later print.c*/
void	print_detail(t_dlst *stack_a, t_dlst *stack_b);
void	print_stack(t_dlst *stack_a, t_dlst *stack_b);
#endif
