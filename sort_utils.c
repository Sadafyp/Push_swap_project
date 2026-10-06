/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:31:35 by syazdanp          #+#    #+#             */
/*   Updated: 2026/10/06 15:39:13 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a, t_stats *stats)
{
	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	if ((*a)->index > (*a)->next->index)
		sa(a, stats);
}
//6 possibilities for 3 numbers: 123, 132, 213, 231, 312, 321

int	find_max_index(t_stack *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	find_min_index(t_stack *stack)
{
	int	min;

	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

/*
** Sorts exactly 3 elements in Stack A using a maximum of 2 moves.
** Uses an optimized else-if structure to avoid extra unwanted rotations.
*/
void	sort_three(t_stack **a, t_stats *stats)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(*a))
		return ;
	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && second < third && first < third)
		sa(a, stats);
	else if (first > second && second > third)
	{
		sa(a, stats);
		rra(a, stats);
	}
	else if (first > second && second < third && first > third)
		ra(a, stats);
	else if (first < second && second > third && first < third)
	{
		sa(a, stats);
		ra(a, stats);
	}
	else if (first < second && second > third && first > third)
		rra(a, stats);
}
