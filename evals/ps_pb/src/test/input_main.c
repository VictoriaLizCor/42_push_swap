// Tests for the functions in input.c
#include "test.h"
#include <stdio.h>

/* Test for splitise
// run:
int	main(int argc, char **argv)
{
	char	**split;
	int		i;
	
	printf("count = %d\n", argc);
	split = splitise(argv, argc);
	i = 0;
	while (split[i] != 0)
	{
		printf("%s\n", split[i]);
		i++;
	}	
	free_split(split);
	return (0);
}
//*/
