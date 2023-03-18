/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:59:56 by iczarnie          #+#    #+#             */
/*   Updated: 2022/04/29 11:59:56 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_front(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
}

t_node	*find_before_last(t_node *stack)
{
	t_node	*temp;

	while (stack->next->next != NULL)
		stack = stack->next;
	temp = stack;
	return (temp);
}

void	do_rrab(t_node **stack, int write, char x)
{
	t_node	*second_last;

	if (*stack && stack && (*stack)->next)
	{
		second_last = find_before_last(*stack);
		add_front(stack, second_last->next);
		second_last->next = NULL;
	}
	if (write)
	{
		ft_putstr_fd("rr", 1);
		ft_putchar_fd(x, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	do_rrr(t_node **stack_a, t_node **stack_b)
{
	do_rrab(stack_a, 0, 'a');
	do_rrab(stack_b, 0, 'b');
	ft_putstr_fd("rrr\n", 1);
}
