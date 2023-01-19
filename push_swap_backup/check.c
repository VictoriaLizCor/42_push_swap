/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:51:35 by lilizarr          #+#    #+#             */
/*   Updated: 2023/01/19 10:35:04 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

int	find_max(t_stack *stack)
{
	int		max;

	max = stack->value;
	while (stack)
	{
		if (max < stack->value)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	check_sorted_idx(t_stack *head)
{
	t_stack	*stack;

	stack = head;
	while (stack)
	{
		if (stack->s_idx == 0)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_min(t_stack *stack)
{
	int		min;

	while (stack)
	{
		if (stack->s_idx == 0)
			break ;
		stack = stack->next;
	}
	min = stack->value;
	while (stack)
	{
		if (stack->s_idx == 0)
		{
			if (min > stack->value)
				min = stack->value;
		}
		stack = stack->next;
	}
	printf("{%d}\n", min);
	return (min);
}

void	sorted_index(t_stack *stack)
{
	t_stack	*head;
	t_stack *head_cpy;
	int		cnt;

	cnt = 0;
	head = stack;
	head_cpy = stack;
	while (stack)
	{
		ft_printf("\nstack |%d | |\t stack| %p \thead| %p\n", stack->value, stack, head);
		if (stack->s_idx == 0 && find_min(head) == stack->value)
			stack->s_idx = ++cnt;
		stack = stack->next;
		print_stack(head_cpy);
		if (stack == NULL)
			stack = head;
		if (check_sorted_idx(head))
			break ;
	}
}

void	check_integers(char **argv)
{
	char	*copy;

	while (*argv)
	{
		if (!*argv)
			ft_error();
		copy = *(argv);
		if (ft_strchr("+-", *copy) || \
			ft_isdigit(*copy))
				copy++;
		while (*copy && ft_isdigit(*copy))
			copy++;
		if (!ft_isdigit(*copy))
		{
			if (!*copy)
				argv++;
			else
				ft_error();
		}
	}
}

void	check_repeated(t_stack *stack)
{
	t_stack	*copy;

	while (stack->next)
	{
		copy = stack->next;
		while (copy)
		{
			if (copy->value == stack->value)
				ft_error();
			copy = copy->next;
		}
		stack = stack->next;
	}
}

// void	check_repeated_arg(char **argv)
// {
// 	char	**copy;
// 	int		len1;
// 	int		len;

// 	while (*argv)
// 	{
// 		copy = argv;
// 		while (*(++copy))
// 		{
// 			len1 = ft_strlen(*argv);
// 			if (len1 >= (int)ft_strlen(*copy))
// 				len = len1;
// 			else
// 				len = (int)ft_strlen(*copy);
// 			if (ft_strncmp(*argv, *(copy), len) == 0)
// 				ft_error();
// 		}
// 		argv++;
// 	}
// }
