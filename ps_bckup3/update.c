/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:27:02 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/01 16:09:36 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_weight(t_stack *stack)
{
	t_stack	*tmp;
	int		mid;

	if (!stack)
		return ;
	tmp = stack;
	// mid = find_max_value(tmp, &(tmp->s_idx)) / 2 + 1;
	mid = find_middle(stack);
	while (stack)
	{
		if (stack->s_idx >= mid)
			stack->weight = -1;
		else
			stack->weight = mid - stack->s_idx;
		stack = stack->next;
	}
}

void	update_idx_stack_a(t_stack *stack)
{
	int	i;

	i = 1;
	while (stack)
	{
		stack->index = i++;
		stack = stack->next;
	}
}

void	update_idx_stack_b(t_stack *stack)
{
	int			i;
	t_stack		*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	while (stack)
	{
		stack->index = i--;
		stack = stack->next;
	}
}
