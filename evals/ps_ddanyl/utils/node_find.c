/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:00:54 by dsas              #+#    #+#             */
/*   Updated: 2023/01/20 17:51:17 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_node_find(t_list *stack, int found)
{
	int		pos;

	if (!stack)
		return (1);
	pos = 0;
	while (stack != NULL)
	{
		if (*(int *)(stack->content) == found)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

int	ft_mid(int size)
{
	if (size % 2 == 0)
		return ((size / 2) + 1);
	return (size / 2);
}

int	ft_min(t_list *stack)
{
	int	min;

	if (!stack)
		return (INT_MAX);
	min = *(int *)(stack->content);
	while (stack != NULL)
	{
		if (*(int *)(stack->content) < min)
			min = *(int *)(stack->content);
		stack = stack->next;
	}
	return (min);
}

int	ft_max(t_list *stack)
{
	int	max;

	if (!stack)
		return (INT_MIN);
	max = *(int *)(stack->content);
	while (stack != NULL)
	{
		if (*(int *)(stack->content) > max)
			max = *(int *)(stack->content);
		stack = stack->next;
	}
	return (max);
}

int	ft_next_max(t_list *stack, int max)
{
	int	next_max;

	if (!stack->next)
		return (0);
	if (*(int *)(stack->content) != max)
		next_max = *(int *)(stack->content);
	else
	{
		next_max = *(int *)(stack->next->content);
		stack = stack->next;
	}
	while (stack != NULL)
	{
		if (*(int *)(stack->content) > next_max \
		&& *(int *)(stack->content) < max)
			next_max = *(int *)(stack->content);
		stack = stack->next;
	}
	return (next_max);
}
