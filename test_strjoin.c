#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*input;
	char	*res;

	printf("Start\n");
	input = ft_strdup("Result");
	printf("input: %s | address: %p\n", input, input);
	res = ft_strjoin("", input);
	printf("Result of joining NULL and a string: %s | address: %p\n", res, res);
}
