/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:33:33 by dsas              #+#    #+#             */
/*   Updated: 2023/01/27 14:03:17 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exec_opposite_moves(t_price *price, t_list **stack_a, t_list **stack_b)
{
	if (price->move_count[0] > 0)
	{
		ft_ra(stack_a);
		price->move_count[0] -= 1;
	}
	if (price->move_count[0] < 0)
	{
		ft_rra(stack_a);
		price->move_count[0] += 1;
	}
	if (price->move_count[1] > 0)
	{
		ft_rb(stack_b);
		price->move_count[1] -= 1;
	}
	if (price->move_count[1] < 0)
	{
		ft_rrb(stack_b);
		price->move_count[1] += 1;
	}
}

void	exec_moves(t_price price, t_list **stack_a, t_list **stack_b)
{
	while (price.move_count[0] != 0 || price.move_count[1] != 0)
	{
		if (price.move_count[0] > 0 && price.move_count[1] > 0)
		{
			ft_rr(stack_a, stack_b);
			price.move_count[0] -= 1;
			price.move_count[1] -= 1;
		}
		else if (price.move_count[0] < 0 && price.move_count[1] < 0)
		{
			ft_rrr(stack_a, stack_b);
			price.move_count[0] += 1;
			price.move_count[1] += 1;
		}
		else
			exec_opposite_moves(&price, stack_a, stack_b);
	}
	ft_pa(stack_a, stack_b);
}

void	ft_sort_big(t_list **stack_a, t_list **stack_b)
{
	int				tp_size;
	int				tp_index;
	int				size_a;
	t_price			*prices;

	if (ft_issorted(*stack_a))
		return ;
	ft_push_not_lls_to_b(stack_a, stack_b);
	while (*stack_b)
	{
		prices = get_transf_price(*stack_a, *stack_b, &tp_size);
		tp_index = pick_best_move_index(prices, tp_size);
		exec_moves(prices[tp_index], stack_a, stack_b);
		free(prices);
	}
	size_a = ft_lstsize(*stack_a);
	if (ft_node_find(*stack_a, ft_max(*stack_a)) <= size_a / 2)
		while (ft_node_find(*stack_a, ft_max(*stack_a)) != size_a - 1)
			ft_ra(stack_a);
	else
		while (ft_node_find(*stack_a, ft_max(*stack_a)) != size_a - 1)
			ft_rra(stack_a);
}
