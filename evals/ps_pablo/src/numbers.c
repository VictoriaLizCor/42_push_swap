/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 20:04:36 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/21 04:24:05 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <limits.h>

//Function turns a string to a long integer type.
long	ft_atol(char *str)
{
	unsigned long long	sum;
	int					sign;

	sum = 0;
	sign = 1;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + (*str - '0');
		str++;
		if (sign == 1 && sum > LONG_MAX)
			return (-1);
		if (sign == -1 && sum > (unsigned long long) LONG_MAX + 1)
			return (-1);
	}
	return ((long) sign * sum);
}

//Function returns the absolute value of an integer.
int	absolute(int num)
{
	if (num < 0)
		return (-1 * num);
	return (num);
}
