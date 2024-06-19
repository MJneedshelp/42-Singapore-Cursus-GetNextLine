/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:33:08 by mintan            #+#    #+#             */
/*   Updated: 2024/06/19 19:33:08 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	int		closechk;
	int		readsz;
	size_t	buffsz;
	char	*buff;

	fd = open("The Raven - Edgar Allen Poe.txt", O_RDONLY);
	printf("fd value: %d\n", fd);
	if (fd == -1)
	{
		printf("Error reading file. Ending the programme now\n");
		return (-1);
	}

	readsz = 10;
	buffsz = 10;
	buff = (char *)malloc(buffsz * sizeof(char));
	while(readsz == buffsz)
	{
		readsz = read(fd, buff, buffsz);
		buff[buffsz] = '\0';
		printf("Read size: %d\n", readsz);
		printf("Read content: %s\n", buff);
	}
	//Do smth here
	//Do smth here
	//Do smth here
	//Do smth here

	closechk = close(fd);
	printf("close value: %d\n", closechk);
	if (closechk == -1)
	{
		printf("Error closing file. Ending the programme now\n");
		return (-1);
	}
	return (0);

}
