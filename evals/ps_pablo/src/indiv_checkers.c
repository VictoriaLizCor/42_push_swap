/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indiv_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:03:13 by pandalaf          #+#    #+#             */
/*   Updated: 2022/11/03 12:24:40 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <limits.h>

//Function checks whether a character is a numeric one.
int	isnumeric(char ch)
{
	if (ft_isdigit(ch) == 1 || ch == '+' || ch == '-')
		return (1);
	return (0);
}

//Function checks whether a string contains a valid signed numeric declaration.
int	isvalidnum(char *str)
{
	int	i;

	if (str[0] == '+' || str[0] == '-')
	{
		i = 1;
		if (str[i] == '\0')
			return (0);
		while (str[i] != '\0')
		{
			if (ft_isdigit(str[i]) == 0)
				return (0);
			i++;
		}
	}
	else
	{
		i = 0;
		while (str[i] != '\0')
		{
			if (ft_isdigit(str[i]) == 0)
				return (0);
			i++;
		}
	}
	return (1);
}

//Function checks whether a string contains an integer-valid number.
int	isinteger(char *str)
{
	long	num;

	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}
