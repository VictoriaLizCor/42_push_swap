/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:01:53 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/17 13:01:10 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <limits.h>

//Function checks that array members contain only digits and numeric symbols.
int	isarrnumeric(char **charr)
{
	int	i;
	int	j;

	i = 0;
	while (charr[i] != 0)
	{
		if (isvalidnum(charr[i]) == 0)
			return (0);
		j = 0;
		while (charr[i][j] != '\0')
		{
			if (isnumeric(charr[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//Function checks that all the array submembers represent only integers.
int	isarrint(char **charr)
{
	int	i;

	if (isarrnumeric(charr) == 0)
		return (0);
	i = 0;
	while (charr[i] != 0)
	{
		if (ft_atol(charr[i]) > (long) INT_MAX)
			return (0);
		if (ft_atol(charr[i]) < (long) INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

//Function checks that there are no duplicate numbers within the main array.
int	isarrdup(char **charr)
{
	int	i;
	int	j;

	if (isarrnumeric(charr) == 0)
		return (-1);
	i = 0;
	while (charr[i] != 0)
	{
		j = 0;
		while (charr[j] != 0)
		{
			if (ft_atol(charr[j]) == ft_atol(charr[i]) && j != i)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

//Function checks whether array members are ordered.
int	isarrsorted(char **charr)
{
	int	i;

	if (isarrnumeric(charr) == 0)
		return (-1);
	i = 0;
	while (charr[i] != 0)
	{
		if (charr[i + 1] == 0)
			break ;
		if (ft_atol(charr[i]) > ft_atol(charr[i + 1]))
			return (0);
		i++;
	}
	return (1);
}
