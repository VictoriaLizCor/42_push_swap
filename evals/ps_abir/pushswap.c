/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:17:11 by mabbas            #+#    #+#             */
/*   Updated: 2022/10/25 00:11:03 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

void	print_list(t_stack	*head)
{
	while (head)
	{
		printf("%2d ", head->val);
		head = head->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (ft_stack_build(argc, argv, &stack_a) == false)
	{
		ft_del_stack(&stack_a);
		return (EXIT_FAILURE);
	}
	size = ft_lst_size(stack_a);
	if (ft_stack_small(size) == true)
		ft_sort_small(&stack_a, &stack_b);
	else if (ft_stack_medium(size) == true || ft_stack_big(size) == true)
		ft_sort_large_elem(&stack_a, &stack_b);
	ft_del_stack(&stack_a);
	ft_del_stack(&stack_b);
	return (0);
}
