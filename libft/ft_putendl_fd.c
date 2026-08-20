/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:01:40 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/25 18:03:31 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters s: The string to output.
fd: The file descriptor on which to write.
Return Value None
External Function write
Description Outputs the string ’s’ to the specified file
descriptor followed by a newline.
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*
#include <fcntl.h>
#include <unistd.h>
int	main(void)
{	int	fd;
	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (1);
	ft_putendl_fd("Hello, World!", fd);
	close(fd);
	return (0);
}
*/