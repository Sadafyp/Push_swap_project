/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:34:04 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/26 14:33:27 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters s: The string to iterate over.
f: The function to apply to each character.
Return Value The string created from the successive applications
of ’f’.
Returns NULL if the allocation fails.
External Function malloc
Description Applies the function f to each character of the
string s, passing its index as the first argument
and the character itself as the second. A new
string is created (using malloc(3)) to store the
results from the successive applications of f.
*/
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	new = malloc(ft_strlen(s) + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
/*
#include <stdio.h>

char	add_index(unsigned int i, char c)
{
	return (c + i);
}
int	main(void)
{
	char *s = "Hello, World!";
	char *result = ft_strmapi(s, add_index);
	if (result != NULL)
	{
		printf("The new string is: '%s'\n", result);
		free(result);
	}
	else
	{
		printf("Memory allocation failed.\n");
	}
	return 0;
}
*/
