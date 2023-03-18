/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:34:37 by mabbas            #+#    #+#             */
/*   Updated: 2022/10/25 01:52:15 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

/**
 * @brief Error Flag is taken as arg
 *        If flag true input invalid ->
 *        display error msg and return true
 * 		  otherwise false.
 * @param error 
 */
void	ft_error_msg(bool error_)
{
	if (error_ == true)
	{
		write(2, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
}

/**
 * @brief Checking if the calculated atoi is in tolerant 
 *        range of int type. If out of range error 
 *        flag is set true by EXIT_FAILURE.
 * 
 * @param res 
 * @param error 
 */

void	ft_range_num_chk(long res, bool *error)
{
	if ((res < INT_MIN) || (res > INT_MAX))
	{
		*error = true;
		ft_error_msg(error);
	}
}

/**
 * @brief A 0 before no will be ignored
 *         -0 not considered an error
          Error flag true if:
		1. Len is > 11 (MIN_INT len incl. - sign)
		2. more than 1 minus sign
		3. Arg not a digit
		4. No arg provided (String empty)
 * 
 * @param str 
 * @param error 
 */
void	ft_check_valid_input(char *str, bool *error)
{
	int	i;

	if (ft_strlen(str) > 11)
		*error = true;
	i = 0;
	if (str[0] == '\0')
		*error = true;
	if (str[i] == '-')
		i++;
	if (str[0] == '-' && str[1] == '\0')
		*error = true;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			*error = true;
		i++;
	}
	ft_error_msg(*error);
}

/*
 * @brief Finds if there is duplicate and print error 
 *        msg accordingly.
 * 
 * @param stack 
 * @return true 
 * @return false 
 */
int	ft_found_duplicate(t_stack *stack)
{
	t_stack	*cur_pos;
	t_stack	*next_node;

	cur_pos = stack;
	next_node = cur_pos;
	while (cur_pos != NULL)
	{
		while (next_node->next != NULL)
		{
			next_node = next_node->next;
			if (cur_pos->val == next_node->val)
				return (EXIT_FAILURE);
		}
		next_node = cur_pos->next;
		cur_pos = cur_pos->next;
	}
	return (EXIT_SUCCESS);
}
