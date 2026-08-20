/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 14:31:04 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/26 14:23:48 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	const char *str = "Hello World!";
	char *result1 = ft_strchr(str, 'o');
	char *result2 = strchr(str, 'o');
	printf("ft_strchr: %s\n", result1);
	printf("strchr: %s\n", result2);
	return (0);
}
	*/
