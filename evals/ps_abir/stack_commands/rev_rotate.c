/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:44:51 by mabbas            #+#    #+#             */
/*   Updated: 2022/10/24 21:04:13 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	ft_revrotate(t_stack **stack)
{
	t_stack	*end;
	t_stack	*current;

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

void	ft_rra(t_stack **stack_a)
{
	ft_revrotate(stack_a);
	write (1, "rra\n", 4);
}

void	ft_rrb(t_stack **stack_b)
{
	ft_revrotate(stack_b);
	write (1, "rrb\n", 4);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
	write (1, "rrr\n", 4);
}
