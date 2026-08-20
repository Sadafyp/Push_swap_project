/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 13:54:03 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/26 14:10:05 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d < s)
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{	char src[50] = "Hello, World!";
	char dst1[50];
	char dst2[50];

	ft_memmove(dst1, src, 13);
	memmove(dst2, src, 13);
	
	printf("ft_memmove: %s\n", dst1); // Hello, World!
	printf("memmove: %s\n", dst2);    // Hello, World!
	return (0);
}
*/
