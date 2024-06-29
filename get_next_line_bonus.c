/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 23:04:34 by mintan            #+#    #+#             */
/*   Updated: 2024/06/29 16:23:14 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Description: Takes in a string and searches for the first \n. Returns the
   index of \n if found. If there is no \n or if the string is NULL, return -1.
   */

int	findn(char *str)
{
	int	pos;

	pos = 0;
	if (str != NULL)
	{
		while (str[pos] != '\0')
		{
			if (str[pos] == '\n')
			{
				return (pos);
			}
			pos++;
		}
	}
	return (-1);
}

/* Description: Frees the remainder and sets it back to NULL. Also frees
   the buff. */
void	freemem(char **rem, char *buff)
{
	if (*rem)
	{
		free (*rem);
		*rem = NULL;
	}
	if (buff)
		free (buff);
}

/* Description: Takes in the remainder and checks remainder for \n. Returns
   a string with the \n if found. If the remainder ends with a \n, the
   remainder is freed and NULL. Otherwise, substring after the \n into a new
   remainder and free + NULL the old remainder.   */

char	*remcheck(char **rem, int npos)
{
	char	*retstr;

	retstr = NULL;
	retstr = ft_substr(*rem, 0, npos + 1);
	if (retstr == NULL)
		return (freemem(rem, NULL), NULL);
	if ((size_t)(npos + 1) == ft_strlen(*rem))
		freemem(rem, NULL);
	else
	{
		ft_memmove(*rem, &(*rem)[npos + 1], ft_strlen(*rem) - (npos + 1));
		(*rem)[ft_strlen(*rem) - (npos + 1)] = '\0';
	}
	return (retstr);
}

/*Description: Takes in a file descriptor and returns a line ending with
  \n each time it is called. Returns a NULL at the end of the file or if
  there is an error in reading the file. */

char	*get_next_line(int fd)
{
	static char	*rem[1024];
	char		*buff;
	int			readsz;
	int			npos;

	npos = findn(rem[fd]);
	readsz = BUFFER_SIZE;
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (npos < 0 && readsz > 0)
	{
		readsz = read(fd, buff, BUFFER_SIZE);
		if (readsz < 0)
			return (freemem(&(rem[fd]), buff), NULL);
		buff[readsz] = '\0';
		rem[fd] = ft_strjoin(&(rem[fd]), buff);
		if (rem[fd] == NULL)
			return (freemem(&(rem[fd]), buff), NULL);
		npos = findn(rem[fd]);
	}
	free (buff);
	if (npos >= 0)
		return (remcheck(&(rem[fd]), npos));
	if (readsz == 0 && rem[fd])
		return (ft_strdup(&(rem[fd])));
	return (NULL);
}
