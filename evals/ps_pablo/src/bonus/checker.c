/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:21:25 by pandalaf          #+#    #+#             */
/*   Updated: 2022/11/06 12:27:23 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../checker.h"
#include <stdlib.h>

//Function interprets a string to check for operations.
static int	read_op(char *str)
{
	if (str == 0)
		return (0);
	if (str[0] == 'p' && str[1] == 'a' && str[2] == '\n')
		return (1);
	if (str[0] == 'p' && str[1] == 'b' && str[2] == '\n')
		return (2);
	if (str[0] == 's' && str[1] == 'a' && str[2] == '\n')
		return (3);
	if (str[0] == 's' && str[1] == 'b' && str[2] == '\n')
		return (4);
	if (str[0] == 's' && str[1] == 's' && str[2] == '\n')
		return (5);
	if (str[0] == 'r' && str[1] == 'a' && str[2] == '\n')
		return (6);
	if (str[0] == 'r' && str[1] == 'b' && str[2] == '\n')
		return (7);
	if (str[0] == 'r' && str[1] == 'r' && str[2] == '\n')
		return (8);
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a' && str[3] == '\n')
		return (9);
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b' && str[3] == '\n')
		return (10);
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r' && str[3] == '\n')
		return (11);
	return (-1);
}

//Function performs the operation on the stacks described by string. Part 2.
void	operate2(char *str, t_stack *stacka, t_stack *stackb)
{
	if (read_op(str) == 7)
		chk_rotate_b(stackb);
	if (read_op(str) == 8)
		chk_rotate_ab(stacka, stackb);
	if (read_op(str) == 9)
		chk_rev_rotate_a(stacka);
	if (read_op(str) == 10)
		chk_rev_rotate_b(stackb);
	if (read_op(str) == 11)
		chk_rev_rotate_ab(stacka, stackb);
}

//Function performs the operation on the stacks described by string. Part 1.
static void	operate1(char *str, t_stack *stacka, t_stack *stackb, char **charr)
{
	if (str == 0)
		return ;
	if (read_op(str) == 1)
		chk_push_a(stacka, stackb);
	if (read_op(str) == 2)
		chk_push_b(stacka, stackb);
	if (read_op(str) == 3)
		chk_swap_a(stacka);
	if (read_op(str) == 4)
		chk_swap_b(stackb);
	if (read_op(str) == 5)
		chk_swap_ab(stacka, stackb);
	if (read_op(str) == 6)
		chk_rotate_a(stacka);
	operate2(str, stacka, stackb);
	if (read_op(str) == -1)
	{
		free(str);
		free_split(charr);
		free_stack(stacka);
		free_stack(stackb);
		display_error();
		exit(0);
	}
}

//Function performs the actions of the checker.
static void	checker(char **charr)
{
	t_stack	*stacka;
	t_stack	*stackb;
	char	*operation;

	stacka = 0;
	stackb = 0;
	stacka = stack_init(0, stacka);
	stackb = stack_init(1, stackb);
	stack_fill(charr, stacka);
	operation = (char *) 1;
	while (operation != 0)
	{
		operation = get_next_line(0);
		operate1(operation, stacka, stackb, charr);
		free(operation);
	}
	if (stack_issorted(stacka) == 1 && stackb->nodecount == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(stacka);
	free_stack(stackb);
}

//Function handles the main program.
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
		ft_printf("OK\n");
		return (0);
	}
	checker(charr);
	free_split(charr);
	return (0);
}
