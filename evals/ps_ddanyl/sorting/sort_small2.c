/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:43:12 by dsas              #+#    #+#             */
/*   Updated: 2023/01/27 13:53:57 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	transfer_below_median(t_list **a, t_list **b, int median)
{
	int	stack_size;
	int	i;

	stack_size = ft_lstsize(*a);
	i = 1;
	while (i <= stack_size)
	{
		if (*(int *)((*a)->content) < median)
			ft_pb(a, b);
		else
			ft_ra(a);
		i++;
	}
}

void	rev_sort_two(t_list **b)
{
	if (*(int *)((*b)->content) < \
		*(int *)((*b)->next->content))
		ft_sb(b);
}

void	rev_sort_three(t_list **b)
{
	int		bottom;
	int		top;
	int		mid;

	top = *(int *)((*b)->content);
	mid = *(int *)((*b)->next->content);
	bottom = *(int *)((*b)->next->next->content);
	if (top < mid && bottom < top)
		ft_sb(b);
	else if (top < mid && mid < bottom)
	{
		ft_sb(b);
		ft_rrb(b);
	}
	else if (bottom < mid && top < bottom)
		ft_rb(b);
	else if (mid < bottom && bottom < top)
	{
		ft_sb(b);
		ft_rb(b);
	}
	else if (mid < top && top < bottom)
		ft_rrb(b);
}
