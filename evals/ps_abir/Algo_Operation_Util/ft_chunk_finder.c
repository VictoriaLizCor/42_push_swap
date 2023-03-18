/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_finder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:38:03 by mabbas            #+#    #+#             */
/*   Updated: 2022/10/17 23:20:43 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"
/**
 * @brief Creating a stack of same elements as in stack a.
 *        Copy the numbers from a to b by libft lst fnc.
 * 
 * @param stack_a 
 * @return t_stack* 
 */
t_stack	*ft_copy_stack(t_stack *stack_a)
{
	t_stack	*stack_key;
	t_stack	*temp_stack;

	stack_key = NULL;
	while (stack_a != NULL)
	{
		temp_stack = ft_new_node(stack_a->val);
		ft_back_add(&stack_key, temp_stack);
		stack_a = stack_a->next;
	}
	return (stack_key);
}

/**
 * @brief We bubble sort the stack. We do it although its O(n^2)
 *        We actually swap the nodes here not the data itself
 *        for accurate results.
 * 
 * @param stack_key 
 */
static void	ft_stack_key(t_stack **stack_key)
{
	t_stack			*stack_node;
	int				ind;
	int				lst_len;
	int				temp;

	stack_node = *stack_key;
	lst_len = ft_lst_size(*stack_key) - 1;
	ind = 0;
	while (lst_len > 0)
	{
		while (ind < lst_len)
		{
			if (stack_node->val > stack_node->next->val)
			{
				temp = stack_node->val;
				stack_node->val = stack_node->next->val;
				stack_node->next->val = temp;
			}
			stack_node = stack_node->next;
			ind++;
		}
		ind = 0;
		stack_node = *stack_key;
		lst_len--;
	}
}

/**
 * @brief We partition the stack_key in no of chunks
 *        depending on stack size.
 *        Then we find the first pos of the key no
 *        Here key means the max element of the first
 *        chunk.
 * 
 * @param stack_key 
 * @param parts 
 * @param move 
 * @return int 
 */
int	ft_next_key(t_stack *stack_key, int slice, int move)
{
	int	pos;
	int	size;
	int	key;

	size = ft_lst_size(stack_key);
	pos = size / slice;
	pos *= move;
	key = ft_pos(stack_key, pos);
	return (key);
}

/**
 * @brief By combining the prev 3 func we get the Key num.
 *        1. Creating a stack_key
 *        2. Sorting it
 *        3. Finding the key num
 *        4. Delete
 * 
 * @param stack_a 
 * @param stack_key 
 * @param parts 
 * @param move 
 * @return int 
 */
int	ft_key(t_stack **stack_a, t_stack **stack_key, int parts, int move)
{
	int	key;

	*stack_key = ft_copy_stack(*stack_a);
	ft_stack_key(stack_key);
	key = ft_next_key(*stack_key, parts, move);
	return (key);
}
