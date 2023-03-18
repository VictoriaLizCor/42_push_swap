/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:26:03 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/11 15:45:21 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	stack_display_full(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	if (node == 0)
	{
		printf("Empty\n");
		return ;
	}
	printf("------------------------Top------------------------\n");
	printf("Val. | Ind. | Pos. | Pos. Tgt. | Cost A | Cost B| next | prev\n");
	while (node != 0)
	{
		printf("%5d  %5d  %5d     %5d     %5d    %5d  %5p  %5p\n", node->value, \
				node->index, node->pos, node->pos_target, node->cost_a, \
				node->cost_b, node->next, node->prev);
		node = node->prev;
	}
}

//Function runs through the algorithm until stack a is sorted.
static int	algorithm(t_stack *stacka, t_stack *stackb)
{
	while (stack_size(stackb) != 0)
	{
		positioning(stacka);
		positioning(stackb);
		targeting(stacka, stackb);
		costing(stacka, stackb);
		perform_operations(stacka, stackb);
	}
	positioning(stacka);
	rotation_a(stacka);
	return (0);
}

//Function sorts a list of numbers using two stacks.
static int	pushswap(char **charr)
{
	t_stack	*stacka;
	t_stack	*stackb;

	stacka = 0;
	stackb = 0;
	stacka = stack_init(0, stacka);
	stackb = stack_init(1, stackb);
	stack_fill(charr, stacka);
	indexing(stacka);
	stack_display_full(stacka);
	if (stack_size(stacka) == 2)
		swap_a(stacka);
	else if (stack_size(stacka) == 3)
		sort_three_a(stacka);
	else
	{
		initial_push_to_b(stacka, stackb);
		sort_three_a(stacka);
		algorithm(stacka, stackb);
	}
	stack_display_full(stacka);
	stack_display_full(stackb);
	free_stack(stacka);
	free_stack(stackb);
	return (0);
}

//Function runs the main program.
int	main(int argc, char **argv)
{
	char	**charr;

	if (argc < 2)
		return (0);
	else if (argc == 2)
		charr = ft_split(argv[1], ' ');
	else
		charr = splitise(argv, argc);
	if (argcheck(charr) == 0)
	{
		free_split(charr);
		return (0);
	}
	if (pushswap(charr) == -1)
		return (0);
	free_split(charr);
	return (0);
}
