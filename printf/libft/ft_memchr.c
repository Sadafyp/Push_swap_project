/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 17:53:03 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/26 14:00:16 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr;

	ptr = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{	const char *str = "Hello World!";
	char *result1 = ft_memchr(str, 'o', 13);
	char *result2 = memchr(str, 'o', 13);
	printf("ft_memchr: %s\n", result1);
	printf("memchr: %s\n", result2);
	return (0);
}
	*/
