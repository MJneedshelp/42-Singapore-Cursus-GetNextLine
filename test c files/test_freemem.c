/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_freemem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:19:01 by mintan            #+#    #+#             */
/*   Updated: 2024/06/29 11:34:22 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = (char *)malloc(5);
	str2 = (char *)malloc(5);
	printf("Step 1. s1: %s | s1 address: %p | s2: %s | s2 address: %p\n", str1, str1, str2, str2);
	freemem(&str1, &str2);
	printf("Step 2. s1: %s | s1 address: %p | s2: %s | s2 address: %p\n", str1, str1, str2, str2);
}
