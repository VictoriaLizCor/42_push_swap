/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:56:56 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/21 14:41:47 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*new_head;
	t_stack	*tail_previous;

	if (!(*stack) || !(*stack)->next)
		return ;
	new_head = stack_last(*stack);
	tail_previous = new_head->previous;
	tail_previous->next = NULL;
	(*stack)->previous = new_head;
	new_head->next = *stack;
	*stack = new_head;
}

static void	rra(t_stack **stack)
{
	reverse_rotate(&*stack);
	ft_printf("rra\n");
	update_idx_stack(*stack);
	update_weight(*stack);
}

static void	rrb(t_stack **stack)
{
	reverse_rotate(&*stack);
	ft_printf("rrb\n");
	update_idx_stack(*stack);
	update_weight(*stack);
}

static void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(&*stack_a);
	reverse_rotate(&*stack_b);
	ft_printf("rrr\n");
	update_idx_stack(*stack_a);
	update_weight(*stack_a);
	update_idx_stack(*stack_b);
	update_weight(*stack_b);
}

void	do_rrotate(t_stack **stack_a, t_stack **stack_b, int type)
{
	if (type == 1)
		rra(&*stack_a);
	else if (type == -1)
		rrb(&*stack_b);
	else if (type == 0)
		rrr(&*stack_a, &*stack_b);
}
