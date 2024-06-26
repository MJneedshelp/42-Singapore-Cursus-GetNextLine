/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_secondreadcheck.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:33:08 by mintan            #+#    #+#             */
/*   Updated: 2024/06/25 17:25:34 by mintan           ###   ########.fr       */
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

	buff = (char *)malloc(100);
	readsz = read(fd, buff, 100);
	buff[readsz] = '\0';
	printf("Readsz: %d | Contents: %s\n", readsz, buff);
	printf("Read again after everything is read\n");
	readsz = read(fd, buff, 100);
	buff[readsz] = '\0';
	printf("Second read. Readsz: %d | Contents: %s\n", readsz, buff);


	closechk = close(fd);
	printf("close value: %d\n", closechk);
	if (closechk == -1)
	{
		printf("Error closing file. Ending the programme now\n");
		return (-1);
	}
	return (0);
}

