/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:31:35 by syazdanp          #+#    #+#             */
/*   Updated: 2026/10/06 15:35:45 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
sorts indexes instead of original values. 
Easier because there are all non negative integers and exactly stack size - 1. 
first turns each index to its binary value then starts with the rightmost digit, 
sees if it’s 0 or 1 : if 0 we push it to stack B 
if 1 we push it to the end of the stack A(ra).  
when all done we push back the whole B to A (pa). 
then we start again this time with the second bit. 
*/

/*for example if max index is 7, binary is 111, 
so we need 3 bits to represent it.*/

static int	count_bits(int max_index)
{
	int	bits;

	bits = 0;
	while (max_index > 0)
	{
		max_index >>= 1;
		bits++;
	}
	return (bits);
}

void	sort_complex(t_stack **a, t_stack **b, t_stats *stats)
{
	int	size;
	int	max_bits;
	int	bit;
	int	i;

	size = stack_size(*a);
	max_bits = count_bits(size - 1);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((*a)->index >> bit) & 1)
				ra(a, stats);
			else
				pb(a, b, stats);
			i++;
		}
		while (*b)
			pa(a, b, stats);
		bit++;
	}
}

/*max_bits = count_bits(size - 1); //max index is size - 1*/