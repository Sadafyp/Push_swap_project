/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 13:33:57 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/26 12:27:22 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stddef.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char str1[50] = "Hello, World!";
	char str2[50] = "Hello, World!";
	
	ft_bzero(str1, 5);
	bzero(str2, 5);
	
	printf("ft_bzero: %s\n", str1); // , World!
	printf("bzero: %s\n", str2);    // , World!
	return (0);
}
*/
