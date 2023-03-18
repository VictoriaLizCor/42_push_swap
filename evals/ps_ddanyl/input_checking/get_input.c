/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:17:04 by dsas              #+#    #+#             */
/*   Updated: 2023/01/26 17:43:17 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long	ft_atol(char *nptr)
{
	int			sign;
	int			i;
	long long	sum;

	sum = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		sum *= 10;
		sum += nptr[i] - '0';
		i++;
	}
	sum *= sign;
	return (sum);
}

int	check_arg(char *arg)
{
	int	i;

	i = -1;
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	while (arg[++i])
	{
		if (! (arg[i] <= '9' && arg[i] >= '0'))
			return (0);
	}
	if (ft_strlen(arg) > 11)
		return (0);
	return (1);
}

int	check_duplicates(int value, t_list **stack_a)
{
	t_list	*tmp;

	if (! *stack_a)
		return (1);
	tmp = *stack_a;
	while (tmp)
	{
		if (*(int *)(tmp->content) == value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_get_input(int argc, char **argv, t_list **stack_a)
{
	long long	current;
	t_list		*node_new;

	*stack_a = NULL;
	if (argc <= 1)
		return (0);
	argc--;
	while (argc)
	{
		if (! check_arg(argv[argc]))
			return (0);
		current = atol(argv[argc]);
		if (current > 2147483647 || current < -2147483648)
			return (0);
		if (! check_duplicates((int)current, stack_a))
			return (0);
		node_new = new_node((int) current);
		if (!node_new)
			return (0);
		ft_lstadd_front(stack_a, node_new);
		argc--;
	}
	return (1);
}
