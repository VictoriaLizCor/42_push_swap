/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:00:05 by pandalaf          #+#    #+#             */
/*   Updated: 2022/11/03 22:37:37 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <stdlib.h>

//Function converts a character array to one compatible with ft_split output.
char	**splitise(char **argv, int argc)
{
	char	**out;
	int		i;

	out = (char **)malloc((argc) * sizeof(char *));
	if (!out)
		return (0);
	i = 0;
	while (i < argc - 1)
	{
		out[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	out[i] = 0;
	return (out);
}

//Function checks that arguments of a string array are valid.
int	argcheck(char **charr)
{
	if (isarrnumeric(charr) == 0)
		return (display_error());
	if (isarrint(charr) == 0)
		return (display_error());
	if (isarrdup(charr) == 1)
		return (display_error());
	if (isarrsorted(charr) == 1)
		return (0);
	return (1);
}
