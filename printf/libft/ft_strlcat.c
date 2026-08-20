/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 12:39:56 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/26 14:29:11 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	while (dst_len < dstsize && dst[dst_len])
		dst_len++;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dstsize == 0 || dst_len >= dstsize)
		return (dstsize + src_len);
	i = 0;
	while (src[i] && (dst_len + i) < (dstsize - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{	char dst[20] = "Hello, ";
	size_t result;
	result = ft_strlcat(dst, "World!", sizeof(dst));
	printf("Returned length: %zu\n", result);
	printf("Destination: %s\n", dst);
	return (0);
}
	*/
