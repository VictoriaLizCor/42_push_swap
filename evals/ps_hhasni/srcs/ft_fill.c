/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 23:32:02 by hhasni            #+#    #+#             */
/*   Updated: 2014/05/13 23:32:04 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void			ft_fill(t_list **l, int nb)
{
	t_list		*tmp;
	t_list		*new;

	tmp = NULL;
	new = NULL;
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return ;
	new->nb = nb;
	new->next = NULL;
	tmp = *l;
	if (!tmp)
		*l = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_list			*ft_fill_first(t_list **l, int nb)
{
	t_list		*new;

	new = NULL;
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->nb = nb;
	new->next = *l;
	return (new);
}
