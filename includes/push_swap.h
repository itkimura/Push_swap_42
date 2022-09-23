/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:53:14 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/23 12:28:26 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# define SORTLIMIT 30

typedef struct s_dlst
{
	int				value;
	int				index;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}					t_dlst;

typedef struct s_qsans
{
	int				index;
	struct s_qsans	*next;
}					t_qsans;

typedef struct s_checker
{
	char				*line;
	struct s_checker	*next;
}					t_checker;

/*
 * total:		total number of input
 * max:			max turn for dfs
 * prev:		previous turn for dfs
 * tmp[]:		current temporary answer by dfs
 * ans[]:		final answer by dfs
 * turn:		total turn fot quick_sort
 * a_next:		a's next index in quick sort
 * b_next:		b's next index in quick sort
 * b_size:		b's stack size
 * q_last:		the last linked list of quick sort answer
 * next_size:	the string to keep the number of input move from stack_b
 */

typedef struct s_sort
{
	int			total;
	int			max;
	int			prev;
	int			tmp[SORTLIMIT + 10];
	int			ans[SORTLIMIT + 10];
	int			turn;
	int			a_next;
	int			b_next;
	int			b_size;
	t_qsans		*q_last;
	int			sort_turn;
	int			next_size[100];
}				t_sort;

enum e_operations{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
};

/* push_swap */
/* push_swap.c */
int		init_ans(t_sort **t);
int		free_all(t_dlst **stack_a, t_dlst **stack_b, t_sort *t);
int		sort(t_dlst *stack_a, t_dlst *stack_b, t_sort *t, int turn);
int		push_swap(int ac, char **av);
int		main(int ac, char **av);

/* dfs.c */
void	update_ans(t_sort *t, int turn);
void	b_dfs(t_dlst *stack_a, t_dlst *stack_b, t_sort *t, int turn);
void	dfs(t_dlst *stack_a, t_dlst *stack_b, t_sort *t, int turn);

/* push_answer.c */
void	print_operations(int index);
void	print_ans(t_sort *t);

/* index.c */
void	int_swap(int *a, int *b);
void	index_sort(int *index, int left, int right);
void	add_index(t_dlst *stack_a, int *index, int total);
int		init_index(t_dlst *stack_a, int total);

/* big_sort.c */
int		b_next_keep(t_dlst *stack_a, t_dlst *stack_b, t_sort *t);
void	half_size(t_dlst *stack_a, t_dlst *stack_b, t_sort *t);
void	b_top(t_dlst *stack_a, t_dlst *stack_b, t_sort *t);
int		big_sort(t_dlst *stack_a, t_dlst *stack_b, t_sort *t);

/* quick_sort.c */
void	b_qs_condition(t_dlst *stack_a, t_dlst *stack_b, t_sort *t, int pivot);
void	b_quick_sort(t_dlst *stack_a, t_dlst *stack_b, t_sort *t);
void	b_sort(t_dlst *stack_a, t_dlst *stack_b, t_sort *t);
void	a_qs_condition(t_dlst *stack_a, t_dlst *stack_b, t_sort *t);
void	a_quick_sort(t_dlst *stack_a, t_dlst *stack_b, t_sort *t);

/* qs_answer.c */
int		new_qsans(t_qsans **a);
void	add_qsans(int op, t_dlst *stack_a, t_dlst *stack_b, t_sort *t);
void	qsans_condition(t_qsans **a);
void	qsans_print(t_qsans *a);
void	free_qsans(t_qsans **a);

/* shared */
/* validation.c */
void	error(void);
int		dublicate_check(int nb, t_dlst **curr);
int		is_valid_nb(char *str, int *i);
int		is_valid_str(char *str, t_dlst **curr, int *total);

/* is_sorted.c */
int		stack_size(t_dlst *stack);
int		is_b_sorted(t_dlst *b, t_sort *t);
int		is_sorted(t_dlst *a, t_dlst *b);

/* init_stack */
t_dlst	*dlstnew(t_dlst *prev, int number);
int		init_dlst(t_dlst **stack_a, t_dlst **stack_b);
void	free_stack(t_dlst **stack);
int		add_stack(char *str, t_dlst **curr, int *total);
int		init_stack(int ac, char **av, t_dlst **stack_a, int *total);

/* operations.c */
int		swap(t_dlst *s);
int		push(t_dlst *a, t_dlst *b);
int		rotate(t_dlst *stack);
int		reverse(t_dlst *stack);

/* apply_operations.c */
bool	avoid_check(int ops, t_sort *t);
int		get_index(char *input);
bool	sort_dlst(t_dlst *stack_a, t_dlst *stack_b, int index, bool recover);
int		recover_dlst(t_dlst *stack_a, t_dlst *stack_b, int index);
int		apply_op(int index, t_dlst *stack_a, t_dlst *stack_b);

/* checker */
/* struct.c */
int		free_stacks(t_dlst **stack_a, t_dlst **stack_b);
int		activate_display(int ac, char **av);
int		new_checker(t_checker **checker);
void	free_checker(t_checker *c);

/* visualizer */
void	v_stack(t_dlst *stack_a, t_dlst *stack_b);
void	visualizer(t_dlst *stack_a, t_dlst *stack_b, char *input);

/*Delete later print.c*/
void	print_detail(t_dlst *stack_a, t_dlst *stack_b);
void	print_stack(t_dlst *stack_a, t_dlst *stack_b, t_sort *t);
#endif
