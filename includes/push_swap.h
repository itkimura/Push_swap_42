#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# define SORTLIMIT 30

/*Delete later*/
# include <stdio.h>

typedef	struct		s_dlst
{
	int				value;
	int				index;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}					t_dlst;

typedef	struct	s_sort
{
	int			total; /* total input */
	int			max;   /* max turn for dfs */
	int			prev;  /* prev turn for dfs */
	int			tmp[SORTLIMIT + 10]; /* current tmp ans for *dfs */
	int			ans[SORTLIMIT + 10]; /* and for dfs */
	int			q_ans[100000]; /* answer for quick sort */
	int			turn; /* total turn for quick sort */
	int			a_next; /* a's next index */
	int			b_next; /* b's next index */
	int			b_size; /* b's next index */
	int			sort_turn;
	int			next_size[100]; /* b's pivot */
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

/* push_swap */

/* dfs.c */
void	b_dfs(t_dlst *stack_a, t_dlst *stack_b, t_sort *t, int turn);
void	dfs(t_dlst *stack_a, t_dlst *stack_b, t_sort *t, int turn);

/* push_answer.c */
void	print_operations(int index);
void	print_ans(t_sort *t);

/* index.c */
int	init_index(t_dlst *stack_a, int total);

/* quick_sort.c */
int		stack_size(t_dlst *stack);
int	big_sort(t_dlst *stack_a, t_dlst *stack_b, t_sort *t);

/* shared */
/* validation.c */
void	error(void);
int	dublicate_check(int nb, t_dlst **curr);
int	is_valid_nb(char *str, int *i);
int	is_valid_str(char *str, t_dlst **curr, int *total);

/* is_sorted.c */
int	is_sorted(t_dlst *a, t_dlst *b);
int	is_b_sorted(t_dlst *b, t_sort *t);

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

/* checker */

/* visualizer */
void	v_stack(t_dlst *stack_a, t_dlst *stack_b);
void	visualizer(t_dlst *stack_a, t_dlst *stack_b, char *input);

/*Delete later print.c*/
void	print_detail(t_dlst *stack_a, t_dlst *stack_b);
void	print_stack(t_dlst *stack_a, t_dlst *stack_b, t_sort *t);
#endif
