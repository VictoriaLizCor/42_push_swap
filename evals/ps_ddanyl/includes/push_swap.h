/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:49:37 by dsas              #+#    #+#             */
/*   Updated: 2023/01/27 16:09:00 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_price {
	int	move_count[2];
	int	val;
}t_price;

int			ft_node_find(t_list *stack, int found);
t_list		*new_node(int i);
void		foo(void *ptr);

void		ft_sa(t_list **stack_a);
void		ft_sb(t_list **stack_b);
void		ft_swap(t_list **stack);
void		ft_ss(t_list **stack_a, t_list **stack_b);
void		ft_ss_no_output(t_list **stack_a, t_list **stack_b);
void		ft_pa(t_list **stack_a, t_list **stack_b);
void		ft_pa_no_output(t_list **stack_a, t_list **stack_b);
void		ft_pb(t_list **stack_a, t_list **stack_b);
void		ft_pb_no_output(t_list **stack_a, t_list **stack_b);
void		ft_rotate(t_list **stack);
void		ft_ra(t_list **stack_a);
void		ft_rb(t_list **stack_b);
void		ft_rr(t_list **stack_a, t_list **stack_b);
void		ft_rr_no_output(t_list **stack_a, t_list **stack_b);
void		ft_revrotate(t_list **stack);
void		ft_rra(t_list **stack_a);
void		ft_rrb(t_list **stack_b);
void		ft_rrr(t_list **stack_a, t_list **stack_b);
void		ft_rrr_no_output(t_list **stack_a, t_list **stack_b);
int			ft_get_input(int argc, char **argv, t_list **stack_a);
long long	ft_atol(char *str);
int			check_arg(char *arg);
int			check_duplicates(int value, t_list **stack_a);

int			ft_node_find(t_list *stack, int found);
int			ft_mid(int size);
int			ft_min(t_list *stack);
int			ft_max(t_list *stack);
int			ft_next_max(t_list *stack, int max);

void		ft_sort_stack(t_list **list);
t_list		*ft_copy_stack(t_list *stack_a);
int			ft_key(t_list **stack_a, t_list **stack_key, int parts, int move);
int			ft_issorted(t_list *stack);

int			value_at_pos(t_list *stack, int pos);

void		ft_sort_big(t_list **stack_a, t_list **stack_b);
void		ft_sort_small(t_list **stack_a, t_list **stack_b);
void		sort_three(t_list **stack);
void		ft_push_not_lls_to_b(t_list **stack_a, t_list **stack_b);

void		put_min_elem_on_top(t_list **stack);
int			*stack_to_arr(t_list *stack);

int			pick_best_move_index(t_price *prices, int prices_size);
t_price		*get_transf_price(t_list *stack_a, \
				t_list *stack_b, int *prices_size);

int			min(int a, int b);
int			max(int a, int b);
int			abs(int a);

void		ft_sort_stack(t_list **list);
void		throw_error(t_list **a);
void		transfer_below_median(t_list **a, t_list **b, int median);
void		rev_sort_two(t_list **b);
void		rev_sort_three(t_list **b);

#endif
