/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:28:23 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/26 14:36:52 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while ((i + j) < len && \
haystack[i + j] == needle[j] && \
needle[j] != '\0')
		{
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{	const char *haystack = "Hello World!";
	const char *needle = "World";
	char *result1 = ft_strnstr(haystack, needle, 13);
	char *result2 = strnstr(haystack, needle, 13);
	printf("ft_strnstr: %s\n", result1);
	printf("strnstr: %s\n", result2);
	return (0);
}
	*/	
