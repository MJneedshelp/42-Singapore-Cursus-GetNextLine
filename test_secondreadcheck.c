/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_secondreadcheck.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:33:08 by mintan            #+#    #+#             */
/*   Updated: 2024/06/25 09:57:26 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		closechk;
	int		readsz;
	size_t	buffsz;
	char	*buff;
	char	*chkstr;
	int		linecount;

	linecount = 0;
	fd = open("testtext2", O_RDONLY);
	printf("fd value: %d\n", fd);
	if (fd == -1)
	{
		printf("Error reading file. Ending the programme now\n");
		return (-1);
	}

// Get_next_line here
while (chkstr != NULL)
{
	chkstr = get_next_line(fd);
	printf("Line no.: %d | Contents: %s\n", linecount, chkstr);
	linecount++;
}
/*
	chkstr = get_next_line(fd);
	printf("First call of gnl: %s\n", chkstr);
*/
	closechk = close(fd);
	printf("close value: %d\n", closechk);
	if (closechk == -1)
	{
		printf("Error closing file. Ending the programme now\n");
		return (-1);
	}
	return (0);
}

