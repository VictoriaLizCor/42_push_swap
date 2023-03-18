/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:50:24 by iczarnie          #+#    #+#             */
/*   Updated: 2022/04/29 11:50:24 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rab(t_node **stack, int write, char x)
{
	t_node	*temp;

	if (*stack && stack && (*stack)->next)
	{
		temp = *stack;
		*stack = (*stack)->next;
		temp->next = NULL;
		add_back(stack, temp);
	}
	if (write)
	{
		ft_putchar_fd('r', 1);
		ft_putchar_fd(x, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	do_rr(t_node **stack_a, t_node **stack_b)
{
	do_rab(stack_a, 0, 'a');
	do_rab(stack_b, 0, 'b');
	ft_putstr_fd("rr\n", 1);
}
