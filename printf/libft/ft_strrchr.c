/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 14:44:17 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/26 14:39:20 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_one;

	last_one = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_one = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)last_one);
}
/*
#include <stdio.h>
#include <string.h>
int main()	{
	const char *str = "Hello World!";
	char *result1 = ft_strrchr(str, 'o');
	char *result2 = strrchr(str, 'o');
	printf("ft_strrchr: %s\n", result1);
	printf("strrchr: %s\n", result2);
	return (0);
}
	*/
