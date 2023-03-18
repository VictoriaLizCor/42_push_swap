/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:04:48 by dsas              #+#    #+#             */
/*   Updated: 2023/01/27 14:02:14 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_closest_move(int i, int size)
{
	if (i <= size / 2)
		return (i);
	else
		return (i - size);
}

int	get_position_in_a(int val, t_list *stack_a)
{
	int		i;
	t_list	*temp;
	t_list	*prev;
	int		size_a;
	int		stack_min;

	i = ft_max(stack_a);
	temp = stack_a->next;
	prev = stack_a;
	size_a = ft_lstsize(stack_a);
	stack_min = ft_min(stack_a);
	if (val > i)
		return (get_closest_move(ft_node_find(stack_a, i), size_a) + 1);
	if (val < stack_min)
		return (get_closest_move(ft_node_find(stack_a, stack_min), size_a));
	i = 1;
	while (temp)
	{
		if (*(int *)(temp->content) > val && *(int *)(prev->content) < val)
			return (get_closest_move(i, size_a));
		prev = temp;
		temp = temp->next;
		i++;
	}
	return (get_closest_move(i, size_a));
}

t_price	*get_transf_price(t_list *stack_a, t_list *stack_b, int *prices_size)
{
	int				b_size;
	t_price			*ret;
	int				i;
	t_list			*temp;

	b_size = ft_lstsize(stack_b);
	i = 0;
	temp = stack_b;
	ret = (t_price *)malloc(sizeof(t_price) * b_size);
	while (temp)
	{
		ret[i].val = *(int *)(temp->content);
		ret[i].move_count[0] = get_position_in_a(ret[i].val, stack_a);
		if (i <= b_size / 2)
			ret[i].move_count[1] = i;
		else
			ret[i].move_count[1] = i - b_size;
		temp = temp->next;
		i++;
	}
	*prices_size = b_size;
	return (ret);
}

int	pick_best_move_index(t_price *prices, int prices_size)
{
	int	i;
	int	best_index;
	int	best_move;
	int	current_move;

	i = 0;
	best_index = -1;
	best_move = INT_MAX;
	current_move = 0;
	while (i < prices_size)
	{
		if (prices[i].move_count[0] * prices[i].move_count[1] > 0)
			current_move = max(abs(prices[i].move_count[0]), \
				abs(prices[i].move_count[1]));
		else
			current_move = abs(prices[i].move_count[0]) + \
				abs(prices[i].move_count[1]);
		if (current_move < best_move)
		{
			best_index = i;
			best_move = current_move;
		}
		i++;
	}
	return (best_index);
}
