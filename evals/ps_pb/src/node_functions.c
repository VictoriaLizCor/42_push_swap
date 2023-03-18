/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:35:44 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/21 02:08:40 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <stdlib.h>

//Function initialises a node with only its value.
t_node	*node_init(int val, t_node *node)
{
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
	{
		ft_printf("Malloc error!\n");
		exit(0);
	}
	node->value = val;
	node->index = 0;
	node->pos = 0;
	node->pos_target = 0;
	node->cost_a = 0;
	node->cost_b = 0;
	return (node);
}

//Function copies values from one node to another.
void	node_inherit(t_node *dest, t_node *source)
{
	dest->value = source->value;
	dest->index = source->index;
	dest->pos = source->pos;
	dest->pos_target = source->pos_target;
	dest->cost_a = source->cost_a;
	dest->cost_b = source->cost_b;
}
