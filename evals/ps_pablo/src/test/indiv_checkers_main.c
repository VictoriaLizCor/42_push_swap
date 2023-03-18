// Tests for the functions in indiv_checkers.c
#include "../../pushswap.h"

//* Test for isvalidnum
// run: cc indiv_checkers_main.c ../indiv_checkers.c ../../libft/libft.a
int	main(void)
{
	char	str1[] = "2324+";
	char	str2[] = "+23411";

	ft_printf("Invalid (%s): %d\n", str1, isvalidnum(str1));
	ft_printf("Valid (%s): %d\n", str2, isvalidnum(str2));
}
//*/

