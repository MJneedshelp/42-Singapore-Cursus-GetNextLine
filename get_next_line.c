/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:52:28 by mintan            #+#    #+#             */
/*   Updated: 2024/06/22 19:21:04 by mintan           ###   ########.fr       */
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
	char		*buff;
	int			readsz;

/******************************************************************************/
	//1. function to check if the FD is readable

	//Test: multiple /n in rem
	/*	
	rem = ft_strdup("1234567890\n0987654321\nqwertyu\n");
	*/
	//Test: in rem, only 1 /n and it is at the end of the string
	/*	
	rem = ft_strdup("12345678900987654321qwertyu\n");
	*/
	//Test: \n is in the first position
	/*
	rem = ft_strdup("\n\n1234wertyu\n");
	*/
	//Test: no \n in rem
	/*
	rem = ft_strdup("kdhfkjsdhfa");
	*/
/******************************************************************************/

//Remainder portion can probably be 1 function

	if (rem)
	{
		npos = findn(rem);
		if (npos >= 0)
		{
			retstr = ft_substr(rem, 0, npos + 1);
			if (retstr == NULL)
			{
				free(rem);
				return (NULL);
			}
			if ((size_t)(npos + 1) == ft_strlen(rem))
			{
				free (rem);
			}
			else
			{
				tmprem = ft_substr(rem, npos + 1, ft_strlen(rem) - (npos + 1));
				if (tmprem == NULL)
				{
					free(rem);
					free(retstr);
					return (NULL);
				}
				free(rem);
				rem = tmprem;
				printf("newrem: %s\n", rem);
			}
			return (retstr);
		}
	}

//Probably need to split the next read part out as a function
	
	readsz = BUFFER_SIZE;

//	while (readsz > 0)	




	//Static var to hold rem string
	//Var to hold the return string

	//1. function to check if the FD is readable
	//2. Check if there is anything in the rem string
	//	- smth in rem string:
	//		- step through rem string to find \n within the rem string -> function to find \n within a string (returns index of first \n)
	//		- if found \n, count strlen up to \n and malloc return string -> can use substring up to \n into return string
	//			- if malloc fails (if substring return is NULL):
	//				- free static variable holding the rem string
	//				- return NULL
	//			- substring rem afer \n of rem string if there is more stuff -> need to free the old reminader and return a new rem
	//			- return return string

	//At this point, 2 possible scenarios:
	//	a. nth in rem string
	//	b. smth in rem string but no \n

	//3. Allocate buff memory for reading
	//4. If malloc fails, return NULL
	//5. While readsize > 0
	//	- read
	//		- if readsize > 0
	//			- step through buff string to find \n within the buff string -> function to find \n within a string (returns index of first \n)
	//			- if found \n, count strlen up to \n. If smth in rem string, add to count and malloc return string -> can use strjoin here
	//				- if malloc fails (if strjoin fails):
	//					- free buff
	//					- if smth in rem string, free static variable holding the rem string
	//					- return NULL
	//				- else
	//					- if smth in rem string
	//						- copy rem string to front of return string -> use strjoin here
	//						- free rem string
	//					- copy buff up to \n to the return string -> use strjoin here
	//					- if there is still smth in buff after \n, malloc rem string -> use substring here
	//						- if malloc fails:
	//							- free return string
	//							- free buff
	//						- else, copy from buff after \n into rem string -> use substring here
	//						- free buff
	//					- return return string
	//		- else (readsize == 0) -> read until the end of the file alr
	//			- free buff
	//			- if smth in rem string,
	//				- return rem string as return string
	//			- else return NULL
}
