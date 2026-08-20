/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:03:59 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/25 18:05:48 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters n: The integer to output.
fd: The file descriptor on which to write.
Return Value None
External Function write
Description Outputs the integer ’n’ to the specified file
descriptor.
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	c = (nb % 10) + '0';
	ft_putchar_fd(c, fd);
}
/*
#include <fcntl.h>
#include <unistd.h>
int	main(void)
{	int	fd;
	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)		return (1);
	ft_putnbr_fd(-12345, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(67890, fd);
	ft_putchar_fd('\n', fd);
	close(fd);
	return (0);
}
*/