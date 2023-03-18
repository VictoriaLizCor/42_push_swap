/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 23:32:33 by hhasni            #+#    #+#             */
/*   Updated: 2014/05/13 23:32:35 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

t_list			*ft_pb(t_list *la, t_list **lb)
{
	if (la)
	{
		write(1, "pb", 2);
		return (ft_fill_first(lb, la->nb));
	}
	return (NULL);
}

t_list			*ft_pa(t_list *lb, t_list **la, int v)
{
	if (lb)
	{
		if (v == 1)
			write(1, "pa", 2);
		else
			write(1, " pa", 3);
		return (ft_fill_first(la, lb->nb));
	}
	return (NULL);
}

void			*ft_ra(t_list *la)
{
	t_list		*tmp;
	t_list		*first;
	t_list		*bkp;

	tmp = la;
	bkp = la;
	first = tmp;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	la = bkp->next;
	first->next = NULL;
	write(1, "ra", 2);
	return (la);
}
