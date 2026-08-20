/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:19:11 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/26 13:35:48 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || \
(c >= 'a' && c <= 'z') || \
(c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/*
#include <stdio.h>

int main(void)
{
    printf("%d\n", ft_isalnum('A')); // 1
    printf("%d\n", ft_isalnum('5')); // 1
    printf("%d\n", ft_isalnum('!')); // 0
}
*/
