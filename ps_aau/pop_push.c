/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:05:15 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/07 14:27:21 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*pop(t_stack **stack_src)
{
	t_stack	*tmp;

	if ((*stack_src)->next)
		(*stack_src)->next->previous = stack_last(*stack_src);
	tmp = (*stack_src);
	(*stack_src) = (*stack_src)->next;
	if ((*stack_src))
		(*stack_src)->previous = stack_last(*stack_src);
	return (tmp);
}

static	void	push_pop(t_stack **stack_src, t_stack **stack_dst)
{
	t_stack	*tmp;

	if (!(*stack_src))
		return ;
	tmp = pop(&*stack_src);
	if (!(*stack_dst))
	{
		(*stack_dst) = tmp;
		(*stack_dst)->previous = NULL;
		(*stack_dst)->next = NULL;
	}
	else
	{
		tmp->next = (*stack_dst);
		(*stack_dst) = tmp;
		(*stack_dst)->previous = stack_last(*stack_dst);
		(*stack_dst)->next->previous = (*stack_dst);
	}
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	push_pop(&*stack_b, &*stack_a);
	ft_printf("pa\n");
	update_idx_stack_a(*stack_a);
	update_idx_stack_a(*stack_b);
	update_weight(*stack_a);
	update_weight(*stack_b);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push_pop(&*stack_a, &*stack_b);
	ft_printf("pb\n");
	update_idx_stack_a(*stack_a);
	update_idx_stack_a(*stack_b);
	update_weight(*stack_a);
	update_weight(*stack_b);
}
