/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:56:56 by lilizarr          #+#    #+#             */
/*   Updated: 2023/01/17 12:10:45 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tail_previous;
	t_stack	*new_tail;

	if (!(*stack) || !(*stack)->next)
		return ;
	new_tail = (*stack);
	tail_previous = stack_last(*stack);
	tail_previous->next = new_tail;
	tail_previous->tail = 0;
	(*stack) = (*stack)->next;
	(*stack)->previous = NULL;
	(*stack)->head = 1;
	new_tail->previous = tail_previous;
	new_tail->next = NULL;
	new_tail->head = 0;
	new_tail->tail = 1;
	update_weight((*stack));
}

void	ra(t_stack **stack)
{
	rotate(&*stack);
	ft_printf("ra\n");
}

void	rb(t_stack **stack)
{
	rotate(&*stack);
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(&*stack_a);
	rotate(&*stack_b);
	ft_printf("rr\n");
}

