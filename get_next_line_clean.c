/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_clean.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:49:14 by mintan            #+#    #+#             */
/*   Updated: 2024/06/27 23:49:14 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//remove <stdio.h> later
#include <stdio.h>
#include "get_next_line.h"

/* Description: Takes in a string and searches for the first \n. Returns the
   index of \n if found. If there is no \n, return -1. */

size_t	findn(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		if (str[pos] == '\n')
		{
			return (pos);
		}
		pos++;
	}
	return (-1);
}

/* Description: Frees the remainder and sets it back to NULL. */
void	freerem(char **rem)
{
	if (rem)
	{
		free (*rem);
		*rem = NULL;
	}
}

/*Description: Takes in a pointer to a string (char **str) and checks if there is \n
  in the string. Also takes in a pointer to an int: status.
  - If there is \n, substring up to the first \n as the return string.
  - If there are more characters after the first \n, memmove it to the front of *str
  remaining string into the location pointed to by (char **dst).
  - If there is no \n, return NULL
  - If any malloc fails, free the set the status to -1
  */

char	*retn(char *str, int *stat)
{
	char	*retstr;
	int		npos;

	retstr = NULL;
	npos = findn(str);
	if (npos >= 0)
	{
		retstr = ft_substr(str, 0, npos + 1);
		if (retstr == NULL)
			return (free(str), (*stat) = -1, NULL);
		if ((size_t)(npos + 1) < ft_strlen(str))
		{
			ft_memmove(str, &(str[npos + 1]), ft_strlen(str) - (npos + 1));
			str[ft_strlen(str) - (npos + 1)] = '\0';
		}
		else
		{
			str[0] = '\0';
		}
	}
	return (retstr);
}

int	main(void)
{
	char	*retstr;
	char	*str;
	int		stat;

	stat = 0;
	str = ft_strdup("0123456\n");
	printf("Or str: %s | Address: %p\n", str, str);
	retstr = retn(str, &stat);
	printf("Ret str: %s | Address: %p\n", retstr, retstr);
	printf("Modified str: %s | Address: %p\n", str, str);
}

