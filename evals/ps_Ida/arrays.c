/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:07:30 by iczarnie          #+#    #+#             */
/*   Updated: 2022/05/13 15:07:30 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*populate_array(t_node *stack, int length)
{
	int	*array;
	int	i;

	i = -1;
	array = (int *)malloc(sizeof(int) * length);
	if (!array)
		return (NULL);
	while (++i < length)
	{
		array[i] = stack->value;
		stack = stack->next;
	}
	return (array);
}

int	*create_and_sort_array(t_node **stack)
{
	int	length;
	int	*array;
	int	i;
	int	j;
	int	temp;

	i = -1;
	length = stack_length(*stack);
	array = populate_array(*stack, length);
	while (++i < length - 1)
	{
		j = i;
		while (++j < length)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	return (array);
}

void	ranks(t_node *stack, int *array)
{
	int	i;

	while (stack)
	{
		i = 0;
		while (array[i] != stack->value)
			i++;
		stack->rank = i;
		stack = stack->next;
	}
}

void	min_max_med(t_node **stack, int *min, int *max, int *med)
{
	int	*array;
	int	length;

	length = stack_length(*stack);
	array = create_and_sort_array(stack);
	*min = array[0];
	*max = array[length - 1];
	*med = array[length / 2];
	ranks(*stack, array);
	free(array);
}
