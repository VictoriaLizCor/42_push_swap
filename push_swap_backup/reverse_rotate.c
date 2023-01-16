/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:56:56 by lilizarr          #+#    #+#             */
/*   Updated: 2023/01/16 17:19:43 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_stack	*ptr;
	int		tmp;

	ptr = stack_last(stack);
	if (!stack || !stack->next)
		return ;
	tmp = stack->value;
	stack->value = ptr->value;
	ptr->value = tmp;
	update_weight(stack);
}

void	rra(t_stack *stack)
{
	reverse_rotate(stack);
	ft_printf("ra\n");
}

void	rrb(t_stack *stack)
{
	reverse_rotate(stack);
	ft_printf("rb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}

