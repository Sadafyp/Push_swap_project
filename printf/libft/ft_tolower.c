/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 14:25:41 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/26 14:45:02 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('b' - 'B'));
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>
int main()
{	int c = 'J';
	printf("Original: %c\n", c);
	printf("Result: %c\n", ft_tolower(c));
	return (0);
}
	*/
