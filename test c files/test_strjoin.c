#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*input;
	char	*res;

	printf("Start\n");
	input = ft_strdup("Test Input");
	printf("input: %s | address: %p\n", input, input);
	res = ft_strjoin(&input, NULL);
	printf("Result of joining NULL and a string: %s | address: %p | Original: %s\n", res, res, input);
}
