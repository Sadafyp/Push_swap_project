/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:28:40 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/26 14:27:38 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters s1: The prefix string.
s2: The suffix string.
Return Value The new string.
NULL if the allocation fails.
External Function malloc
Description Allocates memory (using malloc(3)) and returns a
new string, which is the result of concatenating
’s1’ and ’s2’.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*joined;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	joined = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (joined == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}
/*#include <stdio.h>
#include <string.h>
int main()
{	const char *s1 = "Hello, ";
	const char *s2 = "World!";
	char *result1 = ft_strjoin(s1, s2);
	char *result2 = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
	if (result2 != NULL)
	{	strcpy(result2, s1);
		strcat(result2, s2);	}
	if (result1 != NULL && result2 != NULL)
	{		printf("ft_strjoin: %s\n", result1);
		printf("strjoin: %s\n", result2);
	}
	else
	{		printf("Memory allocation failed\n");
	}
	free(result1);
	free(result2);
	return (0);
} */
