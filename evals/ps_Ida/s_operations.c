/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:30:59 by iczarnie          #+#    #+#             */
/*   Updated: 2022/04/29 14:30:59 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sab(t_node **stack, int write, char x)
{
	t_node	*first;
	t_node	*second;

	if (*stack && stack && (*stack)->next)
	{
		first = *stack;
		second = (*stack)->next;
		(*stack)->next = second->next;
		second->next = first;
		*stack = second;
	}
	if (write)
	{
		ft_putchar_fd('s', 1);
		ft_putchar_fd(x, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	do_ss(t_node **stack_a, t_node **stack_b)
{
	do_sab(stack_a, 0, 'a');
	do_sab(stack_b, 0, 'b');
	ft_putstr_fd("ss\n", 1);
}
