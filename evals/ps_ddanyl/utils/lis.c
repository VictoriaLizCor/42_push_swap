/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:03:09 by dsas              #+#    #+#             */
/*   Updated: 2023/01/25 17:11:02 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	search_replace(int *lis, int left, int right, int key)
{
	int	mid;

	mid = (left + right) / 2;
	while (left <= right)
	{
		if (lis[mid] > key)
			right = mid - 1;
		else if (lis[mid] == key)
			return (mid);
		else if (mid + 1 <= right && lis[mid + 1] >= key)
		{
			lis[mid + 1] = key;
			return (mid + 1);
		}
		else
			left = mid + 1;
		mid = (left + right) / 2;
	}
	if (mid == left)
	{
		lis[mid] = key;
		return (mid);
	}
	lis[mid + 1] = key;
	return (mid + 1);
}

int	*lis_sub(int size, int lis_length, int *arr, int *index)
{
	int	i;
	int	tmp;
	int	*answer;

	answer = (int *)malloc((lis_length + 2) * sizeof(int));
	i = size - 1;
	tmp = lis_length;
	while (i >= 0)
	{
		if (index[i] == tmp)
			answer[tmp--] = arr[i];
		i--;
	}
	return (answer);
}

int	*get_lis(int *arr, int size, int *lis_size, int i)
{
	int	lis_length;
	int	*answer;
	int	*lis;
	int	*index;

	lis_length = -1;
	lis = (int *)malloc(sizeof(int) * size);
	index = (int *)malloc(sizeof(int) * size);
	lis[0] = arr[0];
	i = 1;
	while (i < size)
		lis[i++] = INT_MAX;
	i = 1;
	while (i < size)
	{
		index[i] = search_replace(lis, 0, i, arr[i]);
		if (lis_length < index[i])
			lis_length = index[i];
		i++;
	}
	answer = lis_sub(size, lis_length, arr, index);
	*lis_size = lis_length + 1;
	free(lis);
	free(index);
	return (answer);
}

int	int_in_arr(int n, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == n)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_push_not_lls_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		*list;
	int		list_size;
	int		i;
	int		*arr;

	tmp = ft_copy_stack(*stack_a);
	put_min_elem_on_top(&tmp);
	arr = stack_to_arr(tmp);
	list = get_lis(&arr[1], arr[0], &list_size, 0);
	arr[0] = ft_lstsize(*stack_a);
	i = 1;
	while (i <= arr[0])
	{
		if (int_in_arr(*(int *)((*stack_a)->content), list, list_size))
			ft_ra(stack_a);
		else
			ft_pb(stack_a, stack_b);
		i++;
	}
	ft_lstclear(&tmp, foo);
	free(arr);
	free(list);
}
