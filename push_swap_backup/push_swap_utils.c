/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:20:10 by lilizarr          #+#    #+#             */
/*   Updated: 2023/01/17 15:42:35 by lilizarr         ###   ########.fr       */
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
	printf("\n\n------ %d ------- List HEAD Address : %p\t \t\n", i++, list);
	printf(" Head || Tail  || Value ||  Idx  || Weight || S_Idx ||\t     current      ||\t     previous      ||\t   next\n");
	while (print && i < 10)
	{
		printf("%4d  || %4d  || %4d  || %4d  || %4d   ||%4d   ||   %4p   ||\t  %4p   ||\t\t%4p \n", \
		print->head, print->tail, print->value, \
		print->index, print->weight, print->s_idx, \
		print, print->previous, print->next);
		print = print->next;
		// i++;
	}
	printf("\n\n------------  END LIST ------------\n\n");
	print = list;
}

void	show_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*printa;
	t_stack	*printb;

	printa = stack_a;
	printb = stack_b;
	printf("\n\n------------- HEAD stack_a:%p\t \t HEAD stack_b: %p\t \t\n", \
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

void	check_after_string_data(char *str, int ret, int extra)
{
	int		i;
	char	*buf;

	if ((*str))
	{
		i = 0;
		buf = str;
		printf("\n -- [%p] %zu\n", buf, ft_strlen(buf));
		while (i < ret + extra)
		{
			if (!strchr("\t\n\r\v\f", buf[i]))
				printf("%d_[ %p ]{ %c }", i, (buf + i), *(buf + i));
			else
				printf("%d_[ %p ]( %d )", i, (buf + i),*(buf + i));
			if (i % 2 == 0)
				printf("\t\t");
			else
				printf("\n");
			i++;
		}
	}
	else
		printf("\n ** null \n");
}

t_stack	*stack_last(t_stack *stack)
{
	t_stack	*last;

	last = stack;
	while (last->next)
	{
		last = last->next;
	}
	return (last);
}