#include <stdio.h>

void	test2(void)
{
	printf("Inside second function\n");
}

char	*test(int *stat)
{
	return ((*stat) = -1, test2(), "haha");
}

int	main(void)
{
	int		stat;
	char	*testvar;

	stat = 0;
	printf("Original stat: %d\n", stat);
	testvar = test(&stat);
	printf("testvar: %s\n", testvar);
	printf("Updated stat: %d\n", stat);
}
