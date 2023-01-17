/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:51:35 by lilizarr          #+#    #+#             */
/*   Updated: 2023/01/17 17:32:38 by lilizarr         ###   ########.fr       */
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

int	check_sorted_idx(t_stack *stack)
{
	while (stack)
	{
		if (!stack->s_idx)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	find_min(t_stack *stack)
{
	int		min;

	min = stack->value;
	while (stack)
	{
		if (min > stack->value && !stack->s_idx)
			min = stack->value;
		stack = stack->next;
	}
	ft_printf("{ %d } ", min);
	return (min);
}

void	sorted_index(t_stack *stack)
{
	t_stack	*head;
	int		min;
	int		cnt;

	cnt = 0;
	head = stack;
	while (stack && cnt<10)
	{
		min = find_min(stack);
		ft_printf("\n|%d | %d |\n", stack->value, min);
		if (min == stack->value)
		{
			stack->s_idx = ++cnt; 
			stack = head;
			// min = find_min(stack);
		}
		if (!head->s_idx)
			stack = stack->next;
		else
			head = stack->next;
	}
}
			// if (check_sorted_idx(stack))
			// 	min = find_min(stack);
// void	sorted_index(t_stack *stack)
// {
// 	t_stack	*copy;
// 	int		min;
// 	int		cnt;

// 	while (stack->next)
// 	{
		
// 		copy = stack->next;
// 		while (copy)
// 		{
// 			if (copy->value == stack->value)
// 				ft_error();
// 			copy = copy->next;
// 		}
// 		stack = stack->next;
// 	}
// }

void	check_repeated_arg(char **argv)
{
	char	**copy;
	int		len1;
	int		len;

	while (*argv)
	{
		copy = argv;
		while (*(++copy))
		{
			len1 = ft_strlen(*argv);
			if (len1 >= (int)ft_strlen(*copy))
				len = len1;
			else
				len = (int)ft_strlen(*copy);
			if (ft_strncmp(*argv, *(copy), len) == 0)
				ft_error();
		}
		argv++;
	}
}

		// if (ft_strchr(copy, ' '))
		// {			
		// }
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

// char	**check_strings(char **str)
// {
// 	char 
// }

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

//ft_strncmp(*argv, *(copy), len)

// while (*s != '\0' && (ft_isdigit(*s) || 
//ft_strchr(" +-\t\n\r\v\f", *s) != NULL))
// if ((*s == '+' || *s == '-') && ft_strchr(" +-\t\n\r\v\f", *(s + 1)))

// if (ft_strchr(" +-\t\n\r\v\f", *(*copy) + 1))
// 	ft_error();

// while (*(*copy) && (ft_isdigit(*(*copy)) || \
// ft_strchr("+-", *(*copy)) != NULL))
// if (s[s_i] != c && (s[s_i + 1] == 0 || s[s_i + 1] == c))
// / if (!(*(*copy + 1)) || \
			// ft_strchr("+-", *(*copy)) != NULL)
			// 	(*copy)++;
			// if (!ft_isdigit(*(*copy + 1)))
			// 	ft_error();
			// else
			// 	(*copy)++;
//ft_printf("%c", *(*copy));
//ft_printf("\n*%d\n", ft_atoi(*argv));
