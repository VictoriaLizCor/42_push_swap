/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:20:10 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/17 16:36:58 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

void	print_stack(t_stack *list)
{
	t_stack	*print;
	int		i;

	i = 0;
	print = list;
	ft_printf("\n\n------------- List HEAD Address : %p\t \t\n", list);
	ft_printf("Value ||  Idx  || S_Idx || Weight ||\t     current      ||     previous      ||   next\n");
	while (print && i < 10)
	{
		printf("%ld  ||   %d  ||   %d   ||  %d   ||    %p   ||    %p   ||%p \n", \
		print->value, print->index, print->s_idx, print->weight, \
		print, print->previous, print->next);
		print = print->next;
		// i++;
	}
	ft_printf("\n------------  END LIST ------------\n");
	print = list;
}

void	show_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*printa;
	t_stack	*printb;

	printa = stack_a;
	printb = stack_b;
	ft_printf("\n\n------------- HEAD stack_a:%p\t \t HEAD stack_b: %p\t \t\n", \
	stack_a, stack_b);
	while (printa || printb)
	{
		ft_printf("\n\t");
		if (printa)
		{
			ft_printf(" %d ", printa->value);
			printa = printa->next;
		}
		ft_printf("\t\t ");
		if (printb)
		{
			ft_printf(" %d ", printb->value);
			printb = printb->next;
		}
	}
	ft_printf("\n\t--------- \t---------\n\tstack_a\t\tstack_b\n");
}

int	find_min_value(t_stack *stack, void *value)
{
	int		min;
	int		diff;

	diff = (value - (void *)stack);
	min = *(int *)((void *)stack + diff);
	while (stack)
	{
		if (min > *(int *)((void *)stack + diff))
			min = *(int *)((void *)stack + diff);
		stack = stack->next;
	}
	return (min);
}

int	find_max_value(t_stack *stack, void *value)
{
	int		max;
	int		diff;

	diff = (value - (void *)stack);
	max = *(int *)((void *)stack + diff);
	while (stack)
	{
		if (max < *(int *)((void *)stack + diff))
			max = *(int *)((void *)stack + diff);
		stack = stack->next;
	}
	return (max);
}

void	check_after_string_data(char *str, int ret, int extra)
{
	int		i;
	char	*buf;

	if ((*str))
	{
		i = 0;
		buf = str;
		ft_printf("\n -- [%p] %zu\n", buf, ft_strlen(buf));
		while (i < ret + extra)
		{
			if (!strchr("\t\n\r\v\f", buf[i]))
				ft_printf("%d_[ %p ]{ %c }", i, (buf + i), *(buf + i));
			else
				ft_printf("%d_[ %p ]( %d )", i, (buf + i),*(buf + i));
			if (i % 2 == 0)
				ft_printf("\t\t");
			else
				ft_printf("\n");
			i++;
		}
	}
	else
		ft_printf("\n ** null \n");
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