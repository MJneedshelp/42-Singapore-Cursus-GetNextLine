/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:52:28 by mintan            #+#    #+#             */
/*   Updated: 2024/06/20 20:28:59 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description:
   - Last call of GNL should return a NULL
*/

#include "get_next_line.h"

char	*get_next_line(int fd)
{

	//Static var to hold remainder string
	//Var to hold the return string

	//1. function to check if the FD is readable
	//2. Check if there is anything in the remainder string
	//	- smth in remainder string:
	//		- step through remainder string to find \n within the remainder string -> function to find \n within a string
	//		- if found \n, count strlen up to \n and malloc return string
	//			- if malloc fails:
	//				- free static variable holding the remainder string
	//				- return NULL
	//			- strdup up to \n into return string
	//			- substring remainder afer \n of remainder string
	//			- return remainder string

	//At this point, 2 possible scenarios:
	//	a. nth in remainder string
	//	b. smth in remainder string but no \n

	//3. Allocate buff memory for reading
	//4. If malloc fails, return NULL
	//5. While readsize > 0
	//	- read
	//		- if readsize > 0
	//			- step through buff string to find \n within the buff string -> function to find \n within a string
	//			- if found \n, count strlen up to \n. If smth in remainder string, add to count and malloc return string
	//				- if malloc fails:
	//					- free buff
	//					- if smth in remainder string, free static variable holding the remainder string
	//					- return NULL
	//				- else
	//					- if smth in remainder string
	//						- copy remainder string to front of return string
	//						- free remainder string
	//					- copy buff up to \n to the return string
	//					- if there is still smth in buff after \n, malloc remainder string
	//						- if malloc fails:
	//							- free return string
	//							- free buff
	//						- else, copy from buff after \n into remainder string
	//						- free buff
	//					- return return string
	//		- else (readsize == 0)
	//			- free buff
	//			- if smth in remainder string, count remainder string and malloc return string
	//				- if malloc fails:
	//					- free remainder string
	//				- else, copy remainder into return string
	//				- free remainder string
	//				- return return string
	//			- else return NULL


}
