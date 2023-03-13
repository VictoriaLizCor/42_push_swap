/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:22:17 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/13 15:36:26 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./lib/libft/libft.h"

// # define GET_VAR_NAME(VAR_NAME) #VAR_NAME
/*
value	=	input data
index	=	stack array;
weight	=	idx - value;
head	=	first stack element
tail	=	last stack element
s_idx	=	sorted values index
*/
typedef struct s_stack
{
	int				value;
	int				s_idx;
	int				index;
	int				weight;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stacks_array
{
	const void	*stack;
	char		c_type;
}	t_stacks_array;

typedef struct s_sorted
{
	t_stack			*head_sorted;
	struct s_sorted	*next;
}	t_sorted;

extern int cnt;

/* main */
void	ft_error(void);
void	sort_3(t_stack **stack_a, t_stack **stack_b);
/* Input verification */
/* check.c*/
void	check_integers(char **argv);
void	check_repeated(t_stack *stack);
/* check_utils.c*/
int		find_min(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
/* check_utils2.c*/
int		find_min_s_idx(t_stack *stack);
int		find_max_s_idx(t_stack *stack);
int		find_middle(t_stack *stack);
/* Instructions */
/* swap.c */
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
/* rotate.c */
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
/* reverse_rotate.c */
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);
/* pop_push.c*/
void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);
/* update.c */
void	update_weight(t_stack *stack);
void	update_idx_stack_a(t_stack *stack);
void	update_idx_stack_b(t_stack *stack);
/* Sort_utils.c */
void	sort_index(t_stack *stack);
int		check_sorted_idx(t_stack *head);
int		check_sorted(t_stack *stack);
int		check_sorted_inverse(t_stack *stack);
int		check_sorted_value_inverse(t_stack *stack);
int		check_sorted_value(t_stack *stack);
/* Sortingalgorithm.c */
void	sorting_algorithm(t_stack **stack_a, t_stack **stack_b);
void	divide_sort(t_stack **stack_a, \
t_stack **stack_b, int max_s_idx);
/* testing Utils*/
/* push_swap_utils.c */
int		find_min_value(t_stack *stack, void *value);
int		find_max_value(t_stack *stack, void *value);
void	check_after_string_data(char *str, int ret, int extra);
void	print_stack(t_stack *list);
void	show_stack(t_stack *stack_a, t_stack *stack_b);
#endif