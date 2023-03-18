/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:55:15 by dsas              #+#    #+#             */
/*   Updated: 2023/01/25 15:17:22 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_revrotate(t_list **stack)
{
	t_list	*end;
	t_list	*current;

	if (!stack || !(*stack)->next)
		return ;
	end = *stack;
	current = *stack;
	while (end->next != NULL)
	{
		current = end;
		end = end->next;
	}
	end->next = *stack;
	*stack = end;
	current->next = NULL;
}

void	ft_rra(t_list **stack_a)
{
	ft_revrotate(stack_a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_list **stack_b)
{
	ft_revrotate(stack_b);
	write(1, "rrb\n", 4);
}

void	ft_rrr_no_output(t_list **stack_a, t_list **stack_b)
{
	ft_revrotate(stack_a);
	ft_revrotate(stack_b);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_revrotate(stack_a);
	ft_revrotate(stack_b);
	write(1, "rrr\n", 4);
}
