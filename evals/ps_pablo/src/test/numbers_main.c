// Tests for the functions in numbers.c
#include "../../pushswap.h"
#include <stdio.h>

//* Test for ft_atol
// run: cc numbers_main.c ../numbers.c
int	main(void)
{
	char	str1[] = "+1233112112";
	char	str2[] = "+9223372036854775807";
	char	str3[] = "+9223372036854775808";
	char	str4[] = "-9223372036854775808";
	char	str5[] = "-9223372036854775809";

	printf("atol 1: %ld\n", ft_atol(str1));
	printf("atol 2: %ld\n", ft_atol(str2));
	printf("atol 3: %ld\n", ft_atol(str3));
	printf("atol 4: %ld\n", ft_atol(str4));
	printf("atol 5: %ld\n", ft_atol(str5));
	return (0);
}
//*/
