/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 03:06:24 by mabbas            #+#    #+#             */
/*   Updated: 2022/10/25 01:51:54 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#include "../Includes/push_swap.h"
#include <stdio.h>
/**
 * @brief While using the algo for sorting larger values I use something 
 *        called key to divide the partition and so it is an integral
 *        part of the algo. So I use this func as a indicator to check
 *        the part/elem(nbr) that was pushed which are smaller/equal
 *        to our key number.
 * 
 * @param stack_a 
 * @param key 
 * @return true 
 * @return false 
 */
static	bool	ft_push_chk(t_stack *stack_a, int key)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->val < key)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}

/**
 * @brief Find "Value/Nbr in Stack A and push it to stack B"
 *        To push them we do:
 * 		  1. calculation of stack A size
 *        2. Find middle of stack on stack size
 *        3. Find node pos in the stack
 *        4. Comparing against the middle
 *           if pos <= mid -> rotate to the top( 3 5 9 -> if mid 5 
 *            then 3 is send to the top)
 *           if pos <= mid -> rotate to the bottom
 *        When element reaches pos 0 , push them to the stack B 
 * 
 * @param stack_a 
 * @param stack_b 
 * @param val 
 */
static void	ft_element_push_b(t_stack **stack_a, t_stack **stack_b, int val)
{
	int	mid;
	int	pos;
	int	sz;

	sz = ft_lst_size(*stack_a);
	mid = ft_mid(sz);
	pos = ft_node_find(*stack_a, val);
	while (pos != 1)
	{
		if (pos <= mid)
			ft_ra(stack_a);
		else if (pos > mid)
			ft_rra(stack_a);
		if (ft_sorted_stack(*stack_a) == true)
			return ;
		pos = ft_node_find(*stack_a, val);
	}
	ft_pb(stack_a, stack_b);
}

/**
 * @brief I pushed all elements smaller or equal
 *        to the key number we found earlier
 *        to stack_b 
 * 
 * @param stack_a 
 * @param stack_b 
 * @param key 
 */
static void	ft_push_to_b(t_stack **stack_a, t_stack **stack_b, int key)
{
	t_stack	*tmp;
	int		val;
	int		min;

	tmp = *stack_a;
	while (ft_push_chk(*stack_a, key) == false)
	{
		val = tmp->val;
		if (val <= key)
		{
			ft_element_push_b(stack_a, stack_b, val);
			tmp = *stack_a;
		}
		min = ft_min(*stack_b);
		if (val == min)
			ft_rb(stack_b);
		tmp = tmp->next;
		if (tmp == NULL)
			tmp = *stack_a;
	// printf("in large\n");
	}
}

/**
 * @brief Push all sliced elements the last to stack B
 *        By using ft_slice_set identified the no of
 *        sliced parts. ( sliced )
 *        Left the last part in Stack A to push it in sorted
 *        form in the end 
 *         6 7 8 9 --> stack
 * 
 * @param stack_a 
 * @param stack_b 
 * @param st_key 
 */
static void	push_slice_b(t_stack **stack_a, t_stack **stack_b, t_stack **st_key)
{
	int		move;
	int		slice;
	int		key;
	int		size;

	size = ft_lst_size(*stack_a);
	slice = ft_slice_set(size);
	move = 1;
	key = ft_key(stack_a, st_key, slice, move);
	ft_push_to_b(stack_a, stack_b, key);
	move++;
	if (ft_sorted_stack(*stack_a) == true)
		return ;
	while (move < slice)
	{
		key = ft_next_key(*st_key, slice, move);
		ft_push_to_b(stack_a, stack_b, key);
		move++;
	}
}

/**
 * @brief Algo for Medium/Big(100 or more num)
 *        1. Divide the stack in parts/slices
 *           acc to size
 *        2. Push slices to stack A, except the
 *           last one. Smaller part on
 *           ( 5 6 12 18 19 --> 5,6  ) bottom
 *            of stack B) then comes bigger| 12,18,19
 *	         then it continues.           
 *        3. Sort last part from Stack A to B
 *        4. Sort last 3 elem on Stack A ( 18 12 19)
 *        5. Sort pushed parts back from stack A to B
 *      
 * 
 * @param stack_a 
 * @param stack_b 
 */
void	ft_sort_large_elem(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*st_key;

	if (ft_sorted_stack(*stack_a) == true)
		return ;
	push_slice_b(stack_a, stack_b, &st_key);
	ft_sort_stack_b(stack_a, stack_b);
	if (ft_lst_size(*stack_a) == 3)
		ft_tri_sort(stack_a);
	ft_sort_slice_a(stack_a, stack_b);
	ft_del_stack(&st_key);
}
