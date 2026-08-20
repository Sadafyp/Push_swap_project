/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 14:17:13 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/26 14:45:34 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>
int main()
{
	int c = 'j';
	printf("Original: %c\n", c);
	printf("Result: %c\n", ft_toupper(c));
	return (0);
}
	*/
