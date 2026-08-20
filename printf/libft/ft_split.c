/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 15:10:49 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/27 12:28:06 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters s: The string to be split.
c: The delimiter character.
Return Value The array of new strings resulting from the split.
NULL if any allocation fails.
The returned structure will be released using: 1)
free() on each string in the array; 2) free() the
array itself.
External Function malloc, free
Description Allocates memory (using malloc(3)) and returns an
array of strings obtained by splitting ’s’ using
the character ’c’ as a delimiter.
Each string in the returned array is allocated
independently.
The array of pointers itself is also allocated
dynamically.
The returned array must be NULL terminated.
*/
#include "libft.h"
//#include <stdlib.h>

static	size_t	count_words(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static	void	free_words(char **words, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

static char	**fill_split(char **arr, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			arr[j] = ft_substr(s, start, i - start);
			if (!arr[j])
				return (free_words(arr, j), NULL);
			j++;
		}
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (s == NULL)
		return (NULL);
	arr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	return (fill_split(arr, s, c));
}
/*
#include <stdio.h>
int main()
{	const char *str = "Hello, World! This is a test.";
	char **result = ft_split(str, ' ');
	if (result != NULL)
	{		size_t i = 0;
		while (result[i] != NULL)
		{			printf("Word %zu: '%s'\n", i, result[i]);
			i++;
		}
		i = 0;
		while (result[i] != NULL)
		{			free(result[i]);
			i++;
		}
		free(result);
	}
	else
	{		printf("Memory allocation failed.\n");
	}	return 0;
}*/
