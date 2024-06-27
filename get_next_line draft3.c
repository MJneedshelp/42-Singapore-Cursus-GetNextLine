/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:52:28 by mintan            #+#    #+#             */
/*   Updated: 2024/06/27 15:39:04 by mintan           ###   ########.fr       */
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
			return (free(*rem), (*stat) = -1, NULL);
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

/*Description: Takes in a pointer to a  string and checks if there is \n in the string. If there is*/











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

/******************************************************************************/
	//1. function to check if the FD is readable
/******************************************************************************/
	stat = 0;
	if (rem)
	{
		retstr = remcheck(&rem, &stat);
		if (retstr != NULL || stat == -1)
			return (retstr);
	}

//Probably need to split the next read part out as a function
	//Allocate buffer at the start to store the items to be read
	//Buffer size + 1
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
				//Retrieve the substring up to \n in the buffer -> linen
				linen = ft_substr((const char *)buff, 0, npos + 1);
				if (linen == NULL)
				{
					freerem(&rem);
					return (free(buff), NULL);
				}
				//Check if there's remainder from previous run. Concat rem and linen -> retstr
				if (rem)
				{
					retstr = ft_strjoin(rem, linen);
					if (retstr == NULL)
						return (free(buff), free(rem), free(linen), NULL);
					//Free rem and linen after generating retstr
					freerem(&rem);
					free (linen);
				}
				//No remainder from previous run. linen -> retstr
				else
					retstr = linen;
				//if there is extra content behind the \n in buff, set that content as the new remainder
				//the old remainder should have been destroyed by this time
				if ((npos + 1) < readsz)
				{
					rem = ft_substr(buff, npos + 1, readsz - (npos + 1));
					if (rem == NULL)
						return (free(buff), free(retstr), NULL);
				}
				free (buff);
				//Return for \n is found in new read buff
				return (retstr);
			}
			//No \n found in the buff
			else
			{
				//if rem != NULL, concat rem and buff -> temporary rem
				//Free old rem first and assgin tmprem as new rem
				if (rem)
				{
					tmprem = ft_strjoin(rem, buff);
					if (tmprem == NULL)
						return (free(rem), free(buff), NULL);
					free(rem);
					rem = tmprem;
				}
				//No old rem. Duplicate buff as the new rem. buff is kept to read more in the next loop
				else
					rem = ft_strdup(buff);
			}
		}
	}
	//Readsz == 0, finished reading the file. Free buff and return rem if there is anything left in there. If no rem, return
	//Or readsz == -1, failed read. Free buff. Free rem (if there is smth). Return NULL
	free (buff);
	if (readsz == -1)
		freerem(&rem);
	else if (readsz == 0 && rem != NULL)
	{
		retstr = ft_strdup(rem);
		freerem(&rem);
		return (retstr);
	}
	return (NULL);
}