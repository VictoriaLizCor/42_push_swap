/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:27:02 by lilizarr          #+#    #+#             */
/*   Updated: 2023/01/24 17:23:05 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_weight(t_stack *stack)
{
	while (stack)
	{
		stack->weight = stack->value - stack->s_idx;
		stack = stack->next;
	}
}

void	update_idx_current_stack(t_stack *stack)
{
	int	i;

	i = 1;
	while (stack)
	{
		stack->index = i++;
		stack = stack->next;
	}
}
