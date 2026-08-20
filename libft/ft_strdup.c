/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 18:56:13 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/26 14:25:05 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strdup() function allocates sufficient memory 
for a copy of the string s1, does the copy, 
and returns a pointer to it.  The pointer may 
subsequently be used as an argument to the function free(3).
If insufficient memory is available, 
NULL is returned and errno is set to ENOMEM.
*/
#include "libft.h"
//#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;
	size_t	i;

	len = 0;
	while (s1[len] != '\0')
		len++;
	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{	const char *str = "Hello, World!";
	char *result1 = ft_strdup(str);
	char *result2 = strdup(str);
	if (result1 != NULL && result2 != NULL)
	{		printf("ft_strdup: %s\n", result1);
		printf("strdup: %s\n", result2);
	}
	else
	{		printf("Memory allocation failed\n");
	}
	free(result1);
	free(result2);
	return (0);
} */
