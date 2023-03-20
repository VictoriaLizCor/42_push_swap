/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:48:10 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/08 10:50:21 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <limits.h>
#include <stdlib.h>

//Function pushes all elements to stack b except 3.
void	initial_push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->nodecount != 3)
	{
		// if (stack_index_min(stack_a)->pos <= stack_a->nodecount -2)
		// 	rotate_a(stack_a);
		// else
			push_b(stack_a, stack_b);
	}
}

//Function sorts 3 elements. (Very defined sorting case). Intended for stack a.
void	sort_three_a(t_stack *stack_a)
{
	t_node	*node;

	node = stack_a->bottom->next;
	if (node->next->index > node->index \
		&& node->next->index > node->prev->index)
		rotate_a(stack_a);
	else if (node->index > node->next->index \
			&& node->index > node->prev->index)
		rev_rotate_a(stack_a);
	node = stack_a->bottom->next;
	if (node->next->index > node->index)
		swap_a(stack_a);
}

//Function rotates stack A until it is in order (stack b empty).
void	rotation_a(t_stack *stacka)
{
	int	pos_min;

	pos_min = stack_index_min(stacka)->pos;
	if (pos_min > stacka->nodecount / 2)
	{
		while (pos_min < stacka->nodecount)
		{
			rev_rotate_a(stacka);
			pos_min++;
		}
	}
	else
	{
		while (pos_min > 0)
		{
			rotate_a(stacka);
			pos_min--;
		}
	}
}
