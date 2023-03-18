/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:03:33 by iczarnie          #+#    #+#             */
/*   Updated: 2022/04/29 16:03:33 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pb(t_node **stack_a, t_node **stack_b, int write)
{
	t_node	*from_a;
	t_node	*from_b;

	if (*stack_a && stack_a)
	{
		from_a = *stack_a;
		from_b = *stack_b;
		*stack_a = (*stack_a)->next;
		*stack_b = from_a;
		(*stack_b)->next = from_b;
	}
	if (write)
	{
		ft_putstr_fd("pb\n", 1);
	}
}

void	do_pa(t_node **stack_a, t_node **stack_b, int write)
{
	t_node	*from_a;
	t_node	*from_b;

	if (*stack_b && stack_b)
	{
		from_a = *stack_a;
		from_b = *stack_b;
		*stack_b = (*stack_b)->next;
		*stack_a = from_b;
		(*stack_a)->next = from_a;
	}
	if (write)
	{
		ft_putstr_fd("pa\n", 1);
	}
}
