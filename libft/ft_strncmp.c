/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 14:53:23 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/26 14:34:39 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{	const char *str1 = "Hello World!";
	const char *str2 = "Hello world!";
	int result1 = ft_strncmp(str1, str2, 8);
	int result2 = strncmp(str1, str2, 8);
	printf("ft_strncmp: %d\n", result1); // 0
	printf("strncmp: %d\n", result2);    // 0
	return (0);
}
	*/
