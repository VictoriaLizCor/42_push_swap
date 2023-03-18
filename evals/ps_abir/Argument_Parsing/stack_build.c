/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 02:05:35 by mabbas            #+#    #+#             */
/*   Updated: 2022/10/25 00:14:02 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

/**
 * @brief Delete the whole stack
 * 
 * @param stack 
 */
void	ft_del_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	current = *stack;
	if (!stack || !current)
		return ;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	current = NULL;
}

/**
 * @brief Process the arguments(Without " ")
 *        Conditions for each arg:
          1. New Node Creation
		  2. Convert every arg to a uint with atoi
		  3. assign the input to new node
		  4. Add new node to the end of stack.
 * 
 * @param argc 
 * @param argv 
 * @param stack 
 * @param error 
 */

void	ft_arg_process(int argc, char **argv, t_stack **stack, bool *error)
{
	int		i;
	int		val;
	t_stack	*temp;

	temp = NULL;
	i = 1;
	while (i < argc)
	{
		val = ft_atol(argv[i], error);
		temp = ft_new_node(val);
		ft_back_add(stack, temp);
		i++;
	}
}

/**
 * @brief Freeing the allocated memory from split
 *        Result from split for each index and split function itself
 *        is freed as its a 2D Array(double-pointer). 
 * @param split 
 */
static void	ft_split_free(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

/**
 * @brief Splitting the input arg with the delimiter ' '
 *        For each argument:
 *        1. New Node created
 *        2. Converted every arg to uint with atoi
 *        3. Assigned the input nbr to new node.
 *        4. Adding the node at the end of stack.
 * 
 * @param argv 
 * @param stack 
 * @param error 
 */
static void	ft_split_process(char **argv, t_stack **stack, bool *error)
{
	t_stack	*temp;
	char	**split;
	int		val;
	int		i;

	i = 0;
	temp = NULL;
	split = ft_split(argv[i], ' ');
	while (split[i] != NULL)
	{
		val = ft_atol(split[i], error);
		temp = ft_new_node(val);
		ft_back_add(stack, temp);
		i++;
	}
	ft_split_free(split);
}

/**
 * @brief Dont Create Stack A if:
          1. No arg provided
	      2. Only 1 arg and not betwen " ".
		  Checking valid input. Returns error msg, if:
		  1. Duplicates found.
		  2. Input not a digit
		  3. Overflow of input(type int)
		returns false when error found.otherwise true.
 * 
 * @param argc 
 * @param argv 
 * @param stack 
 * @return true 
 * @return false 
 */

bool	ft_stack_build(int argc, char **argv, t_stack **stack)
{
	static bool	error = false;

	if (argc == 2)
		ft_split_process(argv, stack, &error);
	else if (argc > 2)
		ft_arg_process(argc, argv, stack, &error);
	else if (argc == 1)
		return (false);
	if (argc == 2 && ft_lst_size(*stack) == 0)
		ft_check_valid_input(argv[1], &error);
	if (ft_found_duplicate(*stack) == true)
	{
		ft_del_stack(stack);
		ft_error_msg(true);
	}
	if (ft_lst_size(*stack) == 1)
		return (false);
	return (true);
}
