/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:09:24 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/26 13:45:21 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters n: The integer to convert.
Return Value The string representing the integer.
NULL if the allocation fails.
External Function malloc
Description Allocates memory (using malloc(3)) and returns
a string representing the integer received as an
argument. Negative numbers must be handled.
*/
/*I'm starting from the end of the string and filling in digits*/

#include "libft.h"

static int	ft_nbr_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = n;
	len = ft_nbr_len(nb);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[len - 1] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	return (str);
}
/*
#include <stdio.h>
int main()
{
	int n = -12345;
	char *result = ft_itoa(n);
	if (result != NULL)
	{
		printf("The string representation of %d is: '%s'\n", n, result);
		free(result);
	}
	else
	{
		printf("Memory allocation failed.\n");
	}
	return 0;
}
*/
