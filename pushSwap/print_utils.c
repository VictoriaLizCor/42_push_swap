/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:20:10 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/21 13:16:59 by lilizarr         ###   ########.fr       */
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
	ft_printf("Value ||  Idx  || S_Idx || Weight ||\n");
	// ft_printf("     current      ||     previous      ||   next\n");
	while (print && i < 10)
	{
		ft_printf("%d  ||   %d  ||   %d   ||  %d   ||\n", print->value, print->index, \
		print->s_idx, print->weight);
		// ft_printf("    %p   ||    %p   ||%p \n", \
		// print, print->previous, print->next);
		print = print->next;
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
	ft_printf("\n\n------------- HEAD stack_a:%p\t", stack_a);
	ft_printf(" \t HEAD stack_b: %p\t \t\n", stack_b);
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
		ft_printf("\n -- [%p] %zu\n", buf, ft_strlen(buf));
		while (i < ret + extra)
		{
			if (!strchr("\t\n\r\v\f", buf[i]))
				ft_printf("%d_[ %p ]{ %c }", i, (buf + i), *(buf + i));
			else
				ft_printf("%d_[ %p ]( %d )", i, (buf + i), *(buf + i));
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
