/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_default.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:33:08 by mintan            #+#    #+#             */
/*   Updated: 2024/06/29 14:36:35 by mintan           ###   ########.fr       */
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
	char	*chkstr;
	int		linecount;

	linecount = 0;
	fd = open("Test Input Files/testtext2", O_RDONLY);
	printf("fd value: %d\n", fd);
	chkstr = (char *)malloc(5);
	if (fd == -1)
	{
		printf("Error reading file. Ending the programme now\n");
		return (-1);
	}
	while (chkstr != NULL)
	{
		chkstr = get_next_line(fd);
		printf("Line no.: %d | Contents: %s\n", linecount, chkstr);
		free (chkstr);
		linecount++;
	}
	closechk = close(fd);
	printf("close value: %d\n", closechk);
	if (closechk == -1)
	{
		printf("Error closing file. Ending the programme now\n");
		return (-1);
	}
	return (0);
}
