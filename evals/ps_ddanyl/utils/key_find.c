/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:02:19 by dsas              #+#    #+#             */
/*   Updated: 2023/01/24 10:55:00 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_stack(t_list **list)
{
	int		i;
	int		j;
	int		len;
	t_list	*current;
	int		*tmp;

	i = -1;
	j = 0;
	current = *list;
	len = ft_lstsize(current) - 1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (*(int *)(current->content) > *(int *)(current->next->content))
			{
				tmp = current->content;
				current->content = current->next->content;
				current->next->content = tmp;
			}
			current = current->next;
		}
		current = *list;
	}
}

t_list	*ft_copy_stack(t_list *stack)
{
	t_list	*res;
	t_list	*node_new;

	res = NULL;
	while (stack)
	{
		node_new = ft_lstnew(stack->content);
		ft_lstadd_back(&res, node_new);
		stack = stack->next;
	}
	return (res);
}

int	ft_next_key(t_list *stack, int slice_size, int slice_number)
{
	int	pos;
	int	size;
	int	key;

	size = ft_lstsize(stack);
	pos = size / slice_size;
	pos *= slice_number;
	key = value_at_pos(stack, pos);
	return (key);
}

int	ft_key(t_list **stack_a, t_list **stack_key, int parts, int slice_number)
{
	int	key;

	*stack_key = ft_copy_stack(*stack_a);
	ft_sort_stack(stack_key);
	key = ft_next_key(*stack_key, parts, slice_number);
	return (key);
}
