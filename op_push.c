/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Natasha <Natasha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:31:35 by syazdanp          #+#    #+#             */
/*   Updated: 2026/10/04 19:59:56 by Natasha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
pa: take the top of B and put it on top of A
pb: take the top of A and put it on top of B
*/

void	op_push(t_stack	**src, t_stack **dest)
{
	t_stack	*head;

	if (src == NULL || *src == NULL || dest == NULL)
		return ;
	head = *src;
	*src = (*src)->next;
	head->next = *dest;
	*dest = head;
}

void	pa(t_stack **a, t_stack **b, t_stats *stats)
{
	if (b == NULL || a == NULL || *b == NULL || stats == NULL)
		return ;
	op_push(b, a);
	ft_putstr_fd("pa\n", 1);
	stats->pa++;
	stats->total++;
}

void	pb(t_stack **a, t_stack **b, t_stats *stats)
{
	if (a == NULL || b == NULL || *a == NULL || stats == NULL)
		return ;
	op_push(a, b);
	ft_putstr_fd("pb\n", 1);
	stats->pb++;
	stats->total++;
}
