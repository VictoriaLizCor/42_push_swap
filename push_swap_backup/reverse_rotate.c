/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:56:56 by lilizarr          #+#    #+#             */
/*   Updated: 2023/01/17 13:34:35 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*new_head;
	t_stack	*tail_previous;

	if (!(*stack) || !(*stack)->next)
		return ;
	new_head = stack_last(*stack);
	tail_previous = new_head->previous;
	tail_previous->next = NULL;
	(*stack)->previous = new_head;
	new_head->previous = NULL;
	new_head->tail = 0;
	new_head->head = 1;
	tail_previous->head = 0;
	tail_previous->tail = 1;
	(*stack)->head = 0;
	
	new_head->next = *stack;
	*stack = new_head;
	update_weight((*stack));
}

void	rra(t_stack **stack)
{
	reverse_rotate(&*stack);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack)
{
	reverse_rotate(&*stack);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(&*stack_a);
	reverse_rotate(&*stack_b);
	ft_printf("rrr\n");
}
