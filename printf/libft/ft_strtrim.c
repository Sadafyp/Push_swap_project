/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:35:59 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/26 14:41:40 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters s1: The string to be trimmed.
set: The string containing the set of characters
to be removed.
Return Value The trimmed string.
NULL if the allocation fails.
External Function malloc
Description Allocates memory (using malloc(3)) and returns a
copy of ’s1’ with characters from ’set’ removed
from the beginning and the end.
*/
#include "libft.h"

static	int	ft_is_in_set(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && \
ft_is_in_set(s1[start], (char *)set))
		start++;
	end = ft_strlen(s1);
	while (end > start && \
ft_is_in_set(s1[end - 1], (char *)set))
		end--;
	trimmed = malloc(sizeof(char) * (end - start + 1));
	if (trimmed == NULL)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, end - start + 1);
	return (trimmed);
}
/*
#include <stdio.h>
int main()
{	const char *str = "  Hello, World!  ";
	const char *set = " ";
	char *trimmed = ft_strtrim(str, set);
	if (trimmed != NULL)
	{		printf("Original: '%s'\n", str);
		printf("Trimmed: '%s'\n", trimmed);
	}
	else
	{		printf("Memory allocation failed.\n");
	}
	return 0;
}
*/	
