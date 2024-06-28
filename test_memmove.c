#include "get_next_line.h"
#include <stdio.h>

void	test(char *str)
{
	printf("Inside: %p\n", *str);
	ft_memmove(str, &str[5], 4);
	str[4] = '\0';
}

int	main(void)
{
	char	*str;

	str = ft_strdup("0123\n456\n");
	printf("Or str: %s | Address: %p\n", str, str);
	//printf("Test Address: %p\n", &(str[0]));
	//ft_memmove(str, &(str[5]), 4);
	//str[4] = '\0';
	test(str);
	printf("New str: %s | Address: %p\n", str, str);
}
