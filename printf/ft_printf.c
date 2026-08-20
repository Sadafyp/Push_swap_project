/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 16:53:41 by syazdanp          #+#    #+#             */
/*   Updated: 2026/08/02 17:27:01 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_print_type(format[i + 1], &args);
			i += 2;
		}
		else
		{
			count += ft_print_char(format[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
