/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:03:06 by mintan            #+#    #+#             */
/*   Updated: 2024/06/29 16:24:46 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int	fd1;
	int	fd2;
	int	fd3;

	fd1 = open("Test Input Files/bonus1", O_RDONLY);
	fd2 = open("Test Input Files/bonus1", O_RDONLY);
	fd3 = open("Test Input Files/bonus1", O_RDONLY);

	printf("===========Round 1==========\n");
	printf("Opening file 1: %s\n", get_next_line(fd1));
	printf("Opening file 2: %s\n", get_next_line(fd2));
	printf("Opening file 3: %s\n", get_next_line(fd3));

	printf("===========Round 2==========\n");
	printf("Opening file 1: %s\n", get_next_line(fd1));
	printf("Opening file 2: %s\n", get_next_line(fd2));
	printf("Opening file 3: %s\n", get_next_line(fd3));

	close(fd1);
	close(fd2);
	close(fd3);
}
