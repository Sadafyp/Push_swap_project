/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 12:35:10 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/26 14:11:34 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
/*
#include <stdio.h>
#include <string.h>	
int main()
{
	char str1[50] = "Hello, World!";
	char str2[50] = "Hello, World!";
	
	ft_memset(str1, 'x', 5);
	memset(str2, 'x', 5);
	
	printf("ft_memset: %s\n", str1); // xxxxx, World!
	printf("memset: %s\n", str2);    // xxxxx, World!
	return (0);
}
*/
