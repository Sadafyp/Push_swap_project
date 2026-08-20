/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 16:53:06 by syazdanp          #+#    #+#             */
/*   Updated: 2026/08/02 19:12:38 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, const char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_print_hex(n / 16, base);
	count += ft_print_char(base[n % 16]);
	return (count);
}
