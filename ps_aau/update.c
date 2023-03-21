/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:27:02 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/21 12:23:54 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_weight(t_stack *stack)
{
	t_stack	*tmp;
	int		size;

	if (!stack)
		return ;
	tmp = stack;
	size = find_max_value(tmp, &(tmp->index)) + 1;
	while (stack)
	{
		if (stack->index > size / 2)
			stack->weight = stack->index - size;
		else
			stack->weight = stack->index - 1;
		stack = stack->next;
	}
}

void	update_idx_stack(t_stack *stack)
{
	int	i;

	i = 1;
	while (stack)
	{
		stack->index = i++;
		stack = stack->next;
	}
}
