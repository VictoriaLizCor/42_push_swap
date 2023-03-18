/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:23:17 by dsas              #+#    #+#             */
/*   Updated: 2023/01/26 15:24:14 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int	max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int	abs(int a)
{
	if (a >= 0)
		return (a);
	else
		return (a * (-1));
}
