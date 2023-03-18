/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:08:19 by iczarnie          #+#    #+#             */
/*   Updated: 2022/05/16 17:08:19 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	digits_limits_check(char *argv)
{
	long long int	n;
	int				i;

	i = 0;
	n = ft_atoi(argv);
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) != 1 && argv[i] != '-')
		{
			return (1);
		}
		i++;
	}
	if (n > 2147483647 || n < -2147483648)
		return (1);
	return (0);
}

int	error_check(int argc, char **argv)
{
	int	i;
	int	error;

	i = 1;
	while (i < argc)
	{
		error = digits_limits_check(argv[i]);
		if (error == 1)
			return (1);
		i++;
	}
	return (error);
}

int	duplicate_second(int *first, int *second, int length, t_node **stack_a)
{
	int	i;
	int	j;

	i = -1;
	while (++i < length)
	{
		j = i;
		while (++j < length)
		{
			if (first[i] == second[j])
			{
				free(first);
				free(second);
				free_stack(stack_a);
				return (1);
			}
		}
	}
	free(first);
	free(second);
	return (0);
}

int	duplicate_check(t_node **stack_a)
{
	int	*first;
	int	*second;
	int	length;
	int	result;

	length = stack_length(*stack_a);
	first = create_and_sort_array(stack_a);
	second = create_and_sort_array(stack_a);
	result = duplicate_second(first, second, length, stack_a);
	return (result);
}

void	error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}
