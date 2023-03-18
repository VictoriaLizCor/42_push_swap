/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:43:00 by iczarnie          #+#    #+#             */
/*   Updated: 2022/04/29 16:43:00 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first > second && second < third && first < third)
		do_sab(stack, 1, 'a');
	if (first > second && first > third && second > third)
	{
		do_sab(stack, 1, 'a');
		do_rrab(stack, 1, 'a');
	}
	if (first > second && first > third && second < third)
		do_rab(stack, 1, 'a');
	if (first < second && first < third && second > third)
	{
		do_sab(stack, 1, 'a');
		do_rab(stack, 1, 'a');
	}
	if (first < second && first > third && second > third)
		do_rrab(stack, 1, 'a');
}
