/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:45:39 by dsas              #+#    #+#             */
/*   Updated: 2023/01/24 16:19:43 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*new_node(int i)
{
	int	*i_ptr;

	i_ptr = malloc(sizeof(int));
	if (!i_ptr)
		return (NULL);
	*i_ptr = i;
	return (ft_lstnew(i_ptr));
}

void	foo(void *ptr)
{
	if (ptr == NULL)
		return ;
	return ;
}

int	value_at_pos(t_list *stack, int pos)
{
	int	i;

	i = 0;
	while (i != pos)
	{
		stack = stack->next;
		i++;
	}
	return (*(int *)(stack->content));
}

int	ft_slice_count(int size)
{
	int	slice;

	if (size <= 25)
		slice = 3;
	else if (size <= 50)
		slice = 4;
	else if (size <= 75)
		slice = 5;
	else if (size <= 100)
		slice = 6;
	else
		slice = 14;
	return (slice);
}

int	ft_issorted(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (*(int *)(stack->content) > *(int *)(stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}
