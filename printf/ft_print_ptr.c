/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 16:53:19 by syazdanp          #+#    #+#             */
/*   Updated: 2026/08/02 17:41:47 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_print_address(unsigned long address)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (address >= 16)
		count += ft_print_address(address / 16);
	count += ft_print_char(base[address % 16]);
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	int				count;
	unsigned long	address;

	count = 0;
	address = (unsigned long)ptr;
	if (address == 0)
		count += ft_print_str("(nil)");
	count += ft_print_str("0x");
	count += ft_print_address(address);
	return (count);
}
