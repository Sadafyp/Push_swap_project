/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:14:30 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/26 14:44:12 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters s: The original string from which to create the
substring.
start: The starting index of the substring within
’s’.
len: The maximum length of the substring.
Return Value The substring.
NULL if the allocation fails.
External Function malloc
Description Allocates memory (using malloc(3)) and returns a
substring from the string ’s’.
The substring starts at index ’start’ and has a
maximum length of ’len’.
*/
/* the returned string must be dynamically allocated. 
"" is NOT malloc'd, is a string literal*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substr;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{	const char *str = "Hello, World!";
	unsigned int start = 7;
	size_t len = 5;
	char *result1 = ft_substr(str, start, len);
	char *result2 = strndup(str + start, len);
	if (result1 != NULL && result2 != NULL)
	{		printf("ft_substr: %s\n", result1);
		printf("strndup: %s\n", result2);
	}
	else
	{		printf("Memory allocation failed\n");
	}
	free(result1);
	free(result2);
	return (0);
} */	
