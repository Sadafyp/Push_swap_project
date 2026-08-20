/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 13:40:54 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/26 14:08:29 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char src[50] = "Hello, World!";
	char dst1[50];
	char dst2[50];
	
	ft_memcpy(dst1, src, 13);
	memcpy(dst2, src, 13);
	
	printf("ft_memcpy: %s\n", dst1); // Hello, World!
	printf("memcpy: %s\n", dst2);    // Hello, World!
	return (0);
}
*/
