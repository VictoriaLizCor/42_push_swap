/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:05:04 by dsas              #+#    #+#             */
/*   Updated: 2023/01/25 15:23:43 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_new;

	if (! *stack_b)
		return ;
	node_new = ft_lstnew((*stack_b)->content);
	ft_lstadd_front(stack_a, node_new);
	node_new = *stack_b;
	*stack_b = (*stack_b)->next;
	free(node_new);
	write(1, "pa\n", 3);
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_new;

	if (! *stack_a)
		return ;
	node_new = ft_lstnew((*stack_a)->content);
	ft_lstadd_front(stack_b, node_new);
	node_new = *stack_a;
	*stack_a = (*stack_a)->next;
	free(node_new);
	write(1, "pb\n", 3);
}

void	ft_pa_no_output(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_new;

	if (! *stack_b)
		return ;
	node_new = ft_lstnew((*stack_b)->content);
	ft_lstadd_front(stack_a, node_new);
	node_new = *stack_b;
	*stack_b = (*stack_b)->next;
	free(node_new);
}

void	ft_pb_no_output(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_new;

	if (! *stack_a)
		return ;
	node_new = ft_lstnew((*stack_a)->content);
	ft_lstadd_front(stack_b, node_new);
	node_new = *stack_a;
	*stack_a = (*stack_a)->next;
	free(node_new);
}
