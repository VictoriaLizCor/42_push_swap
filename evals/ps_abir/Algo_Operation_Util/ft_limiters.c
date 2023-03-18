/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_limiters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:04:44 by mabbas            #+#    #+#             */
/*   Updated: 2022/10/23 21:58:54 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

/**
 * @brief Finding the smallest element in stack
 * 
 * @param stack 
 * @return int 
 */
int	ft_min(t_stack	*stack)
{
	int	min;

	if (!stack)
		return (INT_MAX);
	min = stack->val;
	while (stack != NULL)
	{
		if (stack->val < min)
			min = stack->val;
		stack = stack->next;
	}
	return (min);
}

/// @brief Find the biggest element in stack (Check for empty & return INT_MIN)
/// @param stack 
/// @return 
int	ft_max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (INT_MIN);
	max = stack->val;
	while (stack != NULL)
	{
		if (stack->val > max)
			max = stack->val;
		stack = stack->next;
	}
	return (max);
}

/**
 * @brief Find the next biggest element in stack
 * 
 * @param stack 
 * @param max 
 * @return int 
 */
int	ft_next_max(t_stack *stack, int max)
{
	int	next_max;

	if (!stack->next)
		return (0);
	if (stack->val != max)
		next_max = stack->val;
	else
	{
		next_max = stack->next->val;
		stack = stack->next;
	}
	while (stack != NULL)
	{
		if (stack->val > next_max && stack->val < max)
			next_max = stack->val;
		stack = stack->next;
	}
	return (next_max);
}
