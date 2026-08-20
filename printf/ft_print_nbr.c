/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 16:53:13 by syazdanp          #+#    #+#             */
/*   Updated: 2026/08/02 17:26:27 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_positive(long nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
		count += ft_print_positive(nb / 10);
	count += ft_print_char((nb % 10) + '0');
	return (count);
}

int	ft_print_nbr(int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_print_char('-');
		nb = -nb;
	}
	count += ft_print_positive(nb);
	return (count);
}
