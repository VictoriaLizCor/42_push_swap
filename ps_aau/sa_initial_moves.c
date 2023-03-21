/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_initial_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:09:16 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/21 14:41:57 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*target;

	target = find_target_s_idx(*stack_a, -1);
	if (((*stack_a)->s_idx > (*stack_a)->next->s_idx && target->index > 1) || \
	(target->index == 1 && (*stack_a)->previous->index == 2))
	{
		if ((*stack_b) && (*stack_b)->next && \
		(*stack_b)->s_idx < (*stack_b)->next->s_idx)
			do_swap(*stack_a, *stack_b, 0);
		else
			do_swap(*stack_a, *stack_b, 1);
	}
	else if ((*stack_a)->previous && (*stack_a)->previous->index > 2)
	{
		if (target->index == 1)
			do_rotate(&*stack_a, &*stack_b, 1);
		else
			do_rrotate(&*stack_a, &*stack_b, 1);
	}
}

void	push_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	while ((*stack_a)->previous->index > 3)
	{
		if ((*stack_a)->s_idx == size)
			do_rotate(&*stack_a, &*stack_b, 1);
		else
			pb(&*stack_a, &*stack_b);
	}
	while (!check_sorted_value(*stack_a))
		sort_3(&*stack_a, &*stack_b);
}
