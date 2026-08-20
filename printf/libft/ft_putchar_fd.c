/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:50:09 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/26 14:14:44 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters c: The character to output.
fd: The file descriptor on which to write.
Return Value None
External Function write
Description Outputs the character ’c’ to the specified file
descriptor.
*/
/*
Writing to a File Descriptor in C
Once a file descriptor is opened with an access 
mode permitting writing, 
we will be able to write to the file it references 
thanks to the write 
system call from the <unistd.h> library. Its prototype is:

ssize_t write(int fd, const void *buf, size_t count);
And its parameters are as follows:

fd: the file descriptor to write to,
buf: a pointer to a memory zone to write to the file, 
typically containing a string of characters,
count: the number of bytes (i.e. characters) to write, 
typically the length of the string of 
characters specified in the previous parameter.
On success, the write function returns 
the number of bytes it has written, 
However, upon failure, it returns -1 and sets errno to 
indicate the error it encountered.
https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
sample
#include <fcntl.h>
#include <unistd.h> 
int	main(void)
{
	int	fd;

	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (1);
	ft_putchar_fd('H', fd);
	ft_putchar_fd('e', fd);
	ft_putchar_fd('l', fd);
	ft_putchar_fd('l', fd);
	ft_putchar_fd('o', fd);
	ft_putchar_fd('\n', fd);
	close(fd);
	return (0);
}
	*/	
