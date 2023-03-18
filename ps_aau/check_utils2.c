/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:51:35 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/01 16:22:30 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_s_idx(t_stack *tmp)
{
	t_stack	*stack;
	int		min;

	stack = tmp;
	min = stack->s_idx;
	while (stack)
	{
		if (min > stack->s_idx)
			min = stack->s_idx;
		stack = stack->next;
	}
	return (min);
}

int	find_max_s_idx(t_stack *tmp)
{
	t_stack	*stack;
	int		max;

	stack = tmp;

	max = stack->s_idx;
	while (stack)
	{
		if (max < stack->s_idx)
			max = stack->s_idx;
		stack = stack->next;
	}
	return (max);
}

int	find_middle(t_stack *stack)
{
	int	mid;
	int	max;
	int	min;
	
	min = find_min_s_idx(stack);
	max = find_max_s_idx(stack);
	mid = (min + max) / 2;
	return (mid);
}