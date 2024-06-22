/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:08:04 by mintan            #+#    #+#             */
/*   Updated: 2024/06/22 18:08:50 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description: Calculates the length of a given string.Does not include the
   null character '\0'. */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

/* Description: copies n bytes from memory area src to memory area dest. Memory
   must not overlap. */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*x;
	unsigned char	*y;

	x = (unsigned char *)(dest);
	y = (unsigned char *)(src);
	if (dest == NULL && src == NULL)
		return (dest);
	else
	{
		while (n--)
		{
			*x = *y;
			x++;
			y++;
		}
	}
	return (dest);
}

/* Description: Allocates with malloc(3) and returns a substring from the
   string s. The substring begins at index 'start' and is of the maximum size
   'len'. */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (len <= ft_strlen(s) - start)
		ptr = (char *)malloc((len + 1) * sizeof(char));
	else
		ptr = (char *)malloc((ft_strlen(s) - start + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	if (len <= ft_strlen(s) - start)
	{
		ft_memcpy(ptr, (s + start), len);
		*(ptr + len) = '\0';
	}
	else
	{
		ft_memcpy(ptr, (s + start), ft_strlen(s) - start);
		*(ptr + ft_strlen(s) - start) = '\0';
	}
	return (ptr);
}

/* Description: Allocates with malloc(3) and returns a new string, which is
   the result of the concatenation of 's1' and 's2'.
   - s1: prefix
   - s2: suffix
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ptr = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, len1);
	ft_memcpy(ptr + len1, s2, len2);
	*(ptr + len1 + len2) = '\0';
	return (ptr);
}

//to remove the 2 fx below afterwards. They are included for testing only

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (ptr);
	ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}
