/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 17:40:03 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/27 18:39:51 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 The calloc() function contiguously allocates enough space for count objects that
  are size bytes of memory each and returns a pointer to the allocated memory.  
  The allocated memory is filled with bytes of
     value zero. 
	 
42Berlin: Depending on your current operating system, the ’calloc’ function’s
behavior may differ from its man page description. You must follow
this rule: If nmemb or size is 0, then calloc() returns a unique
pointer value that can be successfully passed to free().
*/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			total;
	size_t			i;

	if (size != 0 && nmemb > ((size_t) - 1) / size)
		return (NULL);
	total = nmemb * size;
	ptr = (unsigned char *)malloc(total);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < total)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{	size_t nmemb = 5;
	size_t size = sizeof(int);
	int *result1 = (int *)ft_calloc(nmemb, size);
	int *result2 = (int *)calloc(nmemb, size);
	if (result1 != NULL && result2 != NULL)
	{
		for (size_t i = 0; i < nmemb; i++)
		{			printf("ft_calloc: %d\n", result1[i]);
			printf("calloc: %d\n", result2[i]);
		}
	}
	else
	{		printf("Memory allocation failed\n");
	}	free(result1);
	free(result2);
	return (0);
}
	*/	
