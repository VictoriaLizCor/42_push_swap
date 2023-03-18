/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:34:25 by dsas              #+#    #+#             */
/*   Updated: 2023/01/27 14:42:04 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_list **a)
{
	if (*(int *)((*a)->content) > \
		*(int *)((*a)->next->content))
		ft_sa(a);
}

int	get_stack_mid_val(t_list *stack)
{
	int		ret;
	t_list	*stack_copy;
	int		arr_size;

	stack_copy = ft_copy_stack(stack);
	arr_size = ft_lstsize(stack_copy);
	ft_sort_stack(&stack_copy);
	ret = value_at_pos(stack_copy, arr_size / 2 + 1);
	ft_lstclear(&stack_copy, foo);
	return (ret);
}

void	sort_three(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)((*stack)->content);
	second = *(int *)((*stack)->next->content);
	third = *(int *)((*stack)->next->next->content);
	if ((first > second) && (first < third))
		ft_sa(stack);
	else if ((first > second) && (second > third))
	{
		ft_sa(stack);
		ft_rra(stack);
	}
	else if ((third > second) && (third < first))
		ft_ra(stack);
	else if ((second > third) && (third < first))
	{
		ft_sa(stack);
		ft_ra(stack);
	}
	else if ((second > first) && (first > third))
		ft_rra(stack);
}

void	sort_four_to_six(t_list **a, t_list **b)
{
	int	median;
	int	size_a;
	int	size_b;
	int	return_count;

	return_count = 0;
	median = get_stack_mid_val(*a);
	transfer_below_median(a, b, median);
	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	if (size_a == 2)
		sort_two(a);
	else if (size_a == 3)
		sort_three(a);
	if (size_b == 2)
		rev_sort_two(b);
	else if (size_b == 3)
		rev_sort_three(b);
	while (return_count < size_b)
	{
		ft_pa(a, b);
		return_count++;
	}
}

void	ft_sort_small(t_list **stack_a, t_list **stack_b)
{
	int	size_a;

	size_a = ft_lstsize(*stack_a);
	if (ft_issorted(*stack_a))
		return ;
	if (size_a == 2)
	{
		if (*(int *)((*stack_a)->content) > \
			*(int *)((*stack_a)->next->content))
			ft_sa(stack_a);
	}
	else if (size_a == 3)
		sort_three(stack_a);
	else if (size_a >= 4 && size_a <= 6)
		sort_four_to_six(stack_a, stack_b);
}
