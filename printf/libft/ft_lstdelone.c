/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 21:56:56 by syazdanp          #+#    #+#             */
/*   Updated: 2026/05/26 13:50:48 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters lst: The node to free.
del: The address of the function used to delete
the content.
Return Value None
External Function free
Description Takes a node as parameter and frees its content
using the function ’del’. Free the node itself but
does NOT free the next node.
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}
