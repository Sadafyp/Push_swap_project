/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Natasha <Natasha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:31:35 by syazdanp          #+#    #+#             */
/*   Updated: 2026/10/04 20:02:14 by Natasha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
ra : The first element of stack A becomes the last one. 
	 Shift all elements by one.
rb : The first element of stack B becomes the last one. 
	 Shift all elements by one.
rr : ra and rb at the same time.
*/

void	op_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = first->next;
	last = stack_last(*stack);
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack **a, t_stats *stats)
{
	if (a == NULL || *a == NULL || (*a)->next == NULL || stats == NULL)
		return ;
	op_rotate(a);
	if (!config.count_only)
		ft_putstr_fd("ra\n", 1);
	stats->ra++;
	stats->total++;
}

void	rb(t_stack **b, t_stats *stats)
{
	if (b == NULL || *b == NULL || (*b)->next == NULL || stats == NULL)
		return ;
	op_rotate(b);
	ft_putstr_fd("rb\n", 1);
	stats->rb++;
	stats->total++;
}

void	rr(t_stack **a, t_stack **b, t_stats *stats)
{
	if (((a == NULL || *a == NULL || (*a)->next == NULL)
			&& (b == NULL || *b == NULL || (*b)->next == NULL))
		|| stats == NULL)
		return ;
	op_rotate(a);
	op_rotate(b);
	ft_putstr_fd("rr\n", 1);
	stats->rr++;
	stats->total++;
}
