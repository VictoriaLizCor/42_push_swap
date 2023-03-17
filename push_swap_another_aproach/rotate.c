/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:56:56 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/16 10:57:39 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tail_previous;
	t_stack	*new_tail;

	if (!(*stack) || !(*stack)->next)
		return ;
	new_tail = (*stack);
	tail_previous = stack_last(*stack);
	tail_previous->next = new_tail;
	(*stack) = (*stack)->next;
	new_tail->previous = tail_previous;
	new_tail->next = NULL;
}

void	ra(t_stack **stack)
{
	rotate(&*stack);
	ft_printf("ra\n");
	update_idx_stack_a(*stack);
	update_weight(*stack);
}

void	rb(t_stack **stack)
{
	rotate(&*stack);
	ft_printf("rb\n");
	update_idx_stack_a(*stack);
	update_weight(*stack);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(&*stack_a);
	rotate(&*stack_b);
	ft_printf("rr\n");
	update_idx_stack_a(*stack_a);
	update_weight(*stack_a);
	update_idx_stack_a(*stack_b);
	update_weight(*stack_b);
}

void	do_rotate(t_stack **stack_a, t_stack **stack_b, int type)
{
	if (type == 1)
		ra(&*stack_a);
	else if (type == -1)
		rb(&*stack_b);
	else if (type == 0)
		rr(&*stack_a, &*stack_b);
}
