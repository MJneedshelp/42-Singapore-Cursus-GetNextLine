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
	if (str == NULL)
		return (-1);
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

/*Description: Takes in a pointer to a string (char **str) and checks if
  there is \n in the string. Also takes in a pointer to an int: status.
  - ----------------------------------------------include smth abt the flag-------------------------------------------------------------
  - If there is \n, substring up to the first \n as the return string.
  - If there are more characters after the first \n, memmove it to the
    front of *str remaining string into the location pointed to by
	(char **dst).
  - If there are no characters after the first \n, set \0 at the start of
    the str
  - If there is no \n, return NULL
  - If any malloc fails, free the str and set the status to -1 and
    return NULL
  */

char	*retn(char *str, int *stat, int flag)
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
			ft_memmove(str, &str[npos + 1], ft_strlen(str) - (npos + 1));
			(str)[ft_strlen(str) - (npos + 1)] = '\0';
		}
		else
		{
			if (flag == 0)
				str[0] = '\0';
			if (flag == 1)
				freerem (&str);
		}
	}
	return (retstr);
}

/*Description: Takes in 2 strings: str1 and str2 and performs a string join if
  neither are empty. Returns the following:
  - joined string: if both not empty / NULL
  - str1: if str2 is empty
  - str2: if str1 is empty
  - NULL: if malloc fails, free the incoming str, set status to -1
  //probs need a status as well
  */

 char	*joinstr(char *str1, char *str2, int *stat)
 {
	char	*retstr;

	retstr = ft_strjoin(str1, str2);
	if (retstr == NULL)
	{
		if (str1)
			free(str1);
		if (str2)
			free(str2);
		return ((*stat) = -1, NULL);
	}
	return (retstr);
 }

/* Description:
   - Last call of GNL should return a NULL
*/

 char	*get_next_line_new(int fd)
 {
	static char *rem = NULL;
	char		*retstr;
	char		*buff;
	int			readsz;			//can use as status -> link to while -> break

	readsz = BUFFER_SIZE;
	retstr = retn(rem, &readsz, 1);
	if (retstr != NULL || readsz == -1)
		return (retstr);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (readsz > 0)
	{
		readsz = read(fd, buff, BUFFER_SIZE);
		buff[readsz] = '\0';
		if (readsz > 0)
		{
			retstr = retn(buff, &readsz, 0);
			//if error, free rem (if available) and return NULL
			if (readsz == -1)
				return (freerem(rem), NULL);
			//no new line in buff
			if (retstr == NULL)
			{
				rem = joinstr(rem, buff, readsz);
				{}
			}
			//if no \n in buff and no error
			if (retstr == NULL && readsz > 0)
			{
				rem =
			}
		}
	}

 }

























































/*
int	main(void)
{
	char	*retstr;
	char	*str;
	int		stat;

	stat = 0;
	printf("======================Fx Test: get_next_line: rem check======================\n");
	retstr = get_next_line_new(1);
	printf("First Ret str: %s | Address: %p\n", retstr, retstr);
}
*/


/*
int	main(void)
{
	char	*retstr;
	char	*str;
	int		stat;

	stat = 0;
	printf("======================Fx Test: retn======================\n");
	str = ft_strdup("0123456\n");
	printf("Or str: %s | Address: %p\n", str, str);
	retstr = retn(str, &stat);
	printf("Ret str: %s | Address: %p\n", retstr, retstr);
	printf("Modified str: %s | Address: %p\n", str, str);
}
*/
