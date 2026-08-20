/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 16:53:29 by syazdanp          #+#    #+#             */
/*   Updated: 2026/08/02 17:30:23 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_type(char specifier, va_list *args)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(*args, int)));
	if (specifier == 's')
		return (ft_print_str(va_arg(*args, char *)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_print_nbr(va_arg(*args, int)));
	if (specifier == 'u')
		return (ft_print_unsigned(va_arg(*args, unsigned int)));
	if (specifier == 'x')
		return (ft_print_hex(va_arg(*args, unsigned int), "0123456789abcdef"));
	if (specifier == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	if (specifier == 'p')
		return (ft_print_ptr(va_arg(*args, void *)));
	if (specifier == '%')
		return (ft_print_char('%'));
	return (0);
}
