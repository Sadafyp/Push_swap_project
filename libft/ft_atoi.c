/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:31:35 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/26 12:24:09 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	output;

	i = 0;
	sign = 1;
	output = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		output = output * 10 + (str[i] - '0');
		i++;
	}
	return (output * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{	const char *str = "   -12345abc";
	int result1 = ft_atoi(str);
	int result2 = atoi(str);
	printf("ft_atoi: %d\n", result1);
	printf("atoi: %d\n", result2);
	return (0);
}
	*/
