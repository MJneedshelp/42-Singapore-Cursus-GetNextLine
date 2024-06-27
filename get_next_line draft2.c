/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:52:28 by mintan            #+#    #+#             */
/*   Updated: 2024/06/26 21:58:41 by mintan           ###   ########.fr       */
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
	free (*rem);
	*rem = NULL;
}

/* Description: Takes in the remainder and checks remainder for \n. Returns
   a string with the \n if found. If the remainder ends with a \n, the
   remainder is freed and NULL. Otherwise, substring after the \n into a new
   remainder and free + NULL the old remainder.   */

char	*remcheck(char **rem, int *stat)
{
	char	*retstr;
	char	*tmprem;
	int		npos;

	retstr = NULL;
	npos = findn(*rem);
	if (npos >= 0)
	{
		retstr = ft_substr(*rem, 0, npos + 1);
		if (retstr == NULL)
			return (free(rem), (*stat) = -1, NULL);
		if ((size_t)(npos + 1) == ft_strlen(*rem))
			freerem(rem);
		else
		{
			tmprem = ft_substr(*rem, npos + 1, ft_strlen(*rem) - (npos + 1));
			if (tmprem == NULL)
				return (free(*rem), free(retstr), (*stat) = -1, NULL);
			freerem(rem);
			*rem = tmprem;
		}
	}
	return (retstr);
}

/* Description: Function that takes in up to 3 pointers pointing to allocated
   memory and frees the memory if the pointer is not NULL.
*/
void	freeptr(void *ptr1, void *ptr2, void *ptr3)
{
	if (ptr1 != NULL)
		free (ptr1);
	if (ptr2 != NULL)
		free (ptr2);
	if (ptr3 != NULL)
		free (ptr3);
}



/* Description: Checks if a file can be read
   //probably smth to check if the FD passed in is a binary file or smth
*/


/* Description:
   - Last call of GNL should return a NULL
*/

char	*get_next_line(int fd)
{
	static char *rem = NULL;
	char		*retstr;
	int			npos;
	char		*tmprem;
/******************************************************************************/
	char		*buff;
	char		*linen;
	int			readsz;
	int			stat;

	if (rem)
	{
		retstr = remcheck(&rem, &stat);
		if (retstr != NULL || stat == -1)
			return (retstr);
	}
	readsz = BUFFER_SIZE;
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (readsz > 0)
	{
		readsz = read(fd, buff, BUFFER_SIZE);
		buff[readsz] = '\0';
		if (readsz > 0)
		{
			npos = findn(buff);
			if (npos >= 0)
			{
				linen = ft_substr((const char *)buff, 0, npos + 1);
				if (linen == NULL)
				{
					if (rem)
						free(rem);
					return (free(buff), NULL);
				}
				if (rem)
				{
					retstr = ft_strjoin(rem, linen);
					if (retstr == NULL)
						return (free(buff), free(rem), free(linen), NULL);
					free (rem);
					rem = NULL;
					free (linen);
				}
				else
					retstr = linen;
				if ((npos + 1) < readsz)
				{
					rem = ft_substr(buff, npos + 1, readsz - (npos + 1));
					if (rem == NULL)
						return (free(buff), free(retstr), NULL);
				}
				free (buff);
				return (retstr);
			}
			else
			{
				if (rem)
				{
					tmprem = ft_strjoin(rem, buff);
					if (tmprem == NULL)
						return (free(rem), free(buff), NULL);
					free (rem);
					rem = tmprem;
				}
				else
				{
					rem = ft_strdup(buff);
				}
			}
		}
		else if (readsz == -1)
		{
			free (buff);
			if (rem != NULL)
				free (rem);
			return (NULL);
		}
	}
	if (rem != NULL)
		return (rem);
	return (NULL);
}
