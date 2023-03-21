/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:51:35 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/21 14:42:23 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int val)
{
	if (val < 0)
		val = -val;
	return (val);
}

int	check_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->s_idx + 1 != stack->next->s_idx)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_sorted_value(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->s_idx > stack->next->s_idx)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*find_target_s_idx(t_stack *stack, int type)
{
	t_stack	*tmp1;
	int		target_s_idx;

	tmp1 = stack;
	if (type >= 0)
		target_s_idx = find_min_value(stack, &(stack->s_idx));
	else
		target_s_idx = find_max_value(stack, &(stack->s_idx));
	while (tmp1->s_idx != target_s_idx)
		tmp1 = tmp1->next;
	return (tmp1);
}

t_stack	*last_ordered(t_stack *stack)
{
	t_stack	*tmp_last;

	tmp_last = stack;
	while (tmp_last)
	{
		if (tmp_last->s_idx + 1 != tmp_last->next->s_idx)
			break ;
		tmp_last = tmp_last->next;
	}
	return (tmp_last);
}
