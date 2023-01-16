/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:05:15 by lilizarr          #+#    #+#             */
/*   Updated: 2023/01/16 17:14:42 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop(t_stack **stack_src, t_stack **stack_dst)
{
	t_stack	*tmp;

	if (!(*stack_src))
		return ;
	tmp = (*stack_src);
	(*stack_dst) = (*stack_src);
}

void	push_pop(t_stack **stack_src, t_stack **stack_dst)
{
	t_stack	*tmp;

	if (!(*stack_src))
		return ;
	if ((*stack_src)->next)
	{
		(*stack_src)->next->head = 1;
		(*stack_src)->next->previous = NULL;
	}
	tmp = (*stack_src);
	(*stack_src) = (*stack_src)->next;
	if (!(*stack_dst))
	{
		(*stack_dst) = tmp;
		(*stack_dst)->next = NULL;
		(*stack_dst)->tail = 1;
	}
	else
	{
		tmp->next = (*stack_dst);
		(*stack_dst) = tmp;
		(*stack_dst)->next->previous = (*stack_dst);
		(*stack_dst)->next->head = 0;
		(*stack_dst)->tail = 0;
	}
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	push_pop(&*stack_b, &*stack_a);
	update_weight(*stack_a);
	update_weight(*stack_b);
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push_pop(&*stack_a, &*stack_b);
	update_weight(*stack_a);
	update_weight(*stack_b);
	ft_printf("pb\n");
}
