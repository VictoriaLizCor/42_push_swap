/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 23:32:41 by hhasni            #+#    #+#             */
/*   Updated: 2014/05/13 23:32:43 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void				ft_debug_first(int v, t_list *la, t_list *lb)
{
	t_list			*tmp;
	t_list			*tmpb;

	tmp = la;
	tmpb = lb;
	if (v == 1)
	{
		write(1, "\nLA = ", 6);
		while (tmp)
		{
			ft_putnbr(tmp->nb);
			write (1, " ", 1);
			tmp = tmp->next;
		}
		write(1, "\nLB = ", 7);
		while (tmpb)
		{
			ft_putnbr(tmpb->nb);
			write (1, " ", 1);
			tmpb = tmpb->next;
		}
		write(1, "\n", 1);
	}
}

void				ft_debug_second(int v, t_list *la, t_list *lb)
{
	t_list			*tmp;
	t_list			*tmpb;

	tmp = la;
	tmpb = lb;
	if (v == 1)
	{
		write(1, "\nLA = ", 6);
		while (tmp)
		{
			ft_putnbr(tmp->nb);
			write (1, " ", 1);
			tmp = tmp->next;
		}
		write(1, "\nLB = ", 7);
		while (tmpb)
		{
			ft_putnbr(tmpb->nb);
			write (1, " ", 1);
			tmpb = tmpb->next;
		}
		write(1, "\n", 1);
	}
}

static t_list		*ft_tidy(t_list *lb, t_list *tmp, int v)
{
	while (lb)
	{
		tmp = ft_pa(lb, &tmp, v);
		lb = lb->next;
		if (v == 1)
			ft_debug_second(v, tmp, lb);
	}
	return (tmp);
}

void				ft_pushswap(t_list *la, t_list *lb, int v)
{
	t_list			*tmp;

	tmp = la;
	while (ft_is_order(tmp) == -1)
	{
		if (ft_is_min(tmp->nb, tmp) == 1)
		{
			lb = ft_pb(tmp, &lb);
			tmp = tmp->next;
		}
		else
			tmp = ft_ra(tmp);
		if (ft_is_order(tmp) == -1)
			write(1, " ", 1);
		ft_debug_first(v, tmp, lb);
	}
	tmp = ft_tidy(lb, tmp, v);
}
