/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:22:17 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/21 14:46:48 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./lib/libft/libft.h"

/*
** value = input data
** index = stack array;
** weight = idx - value;
** s_idx = sorted values index
*/
typedef struct s_stack
{
	int				value;
	int				s_idx;
	int				index;
	int				weight;
	struct s_stack	*previous;
	struct s_stack	*next;
}				t_stack;

typedef struct s_targets
{
	t_stack		*a;
	t_stack		*b;
}				t_targets;
/*
** push_swap.c
*/
t_stack	*stack_last(t_stack *stack);
/*
** Input verification: check_error.c
*/
void	check_integers(char **argv);
void	check_repeated(t_stack *stack);
/*
** Sorting_algorithm.c
*/
void	sorting_algorithm(t_stack **stack_a, t_stack **stack_b);
/*
** sa_initial_moves.c
*/
void	push_b(t_stack **stack_a, t_stack **stack_b, int size);
/*
** sort_utils2.c
*/
int		abs(int val);
int		check_sorted(t_stack *stack);
int		check_sorted_value(t_stack *stack);
t_stack	*find_target_s_idx(t_stack *stack, int type);
t_stack	*last_ordered(t_stack *stack);
/*
** sort_utils2.c
*/
int		find_min_value(t_stack *stack, void *value);
int		find_max_value(t_stack *stack, void *value);
void	sort_index(t_stack *stack);
/*
** Instructions: swap.c
*/
void	do_swap(t_stack *stack_a, t_stack *stack_b, int type);
/*
** Instructions:rotate.c
*/
void	do_rotate(t_stack **stack_a, t_stack **stack_b, int type);
/*
** Instructions:reverse_rotate.c
*/
void	do_rrotate(t_stack **stack_a, t_stack **stack_b, int type);
/*
** Instructions:pop_push.c
*/
void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);
/*
** update.c
*/
void	update_weight(t_stack *stack);
void	update_idx_stack(t_stack *stack);
/*
** testing Utils: print_utils.c
*/
void	check_after_string_data(char *str, int ret, int extra);
void	print_stack(t_stack *list);
void	show_stack(t_stack *stack_a, t_stack *stack_b);
#endif
