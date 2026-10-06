/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Natasha <Natasha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:31:35 by syazdanp          #+#    #+#             */
/*   Updated: 2026/10/04 20:09:05 by Natasha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
Medium algorithm (O(n√n)):
Chunk-based sorting (divide into √n chunks)
*/

/*
** Returns the ideal chunk size based on the total amount of numbers.
** For 100 numbers, 4-5 chunks are recommended (chunk size ~20-25).
** For 500 numbers, 9-11 chunks are recommended (chunk size ~45-50).
*/

/*
More dynamically, 
** the chunk size can be determined by a sliding-window 
approach proportional to sqrt(n).
** Approximately 20 for n=100 and 46 for n=500.
*/
/*static int	get_chunk_size(int size)
{
	/*
	if (size <= 100)
		return (22);
	return (48);
	
	// Dynamic chunk size based on the square root of the total size
	int	chunk;

	chunk = 1;
	while (chunk * chunk < size)
		chunk++;
	return (chunk * 2);
}*/

static int	get_chunk_size(int size)
{
	int	chunk;

	chunk = 1;
	while (chunk * chunk < size)
		chunk++;
	return (chunk * 2);
}

/*
** Pushes numbers from stack A to stack B by dividing them into chunks.
** If the current element's index belongs to the active chunk, 
it is sent to B (pb).
** Optimization: if the index is in the lower half of the chunk, 
   we rotate B (rb)
** to pre-sort stack B dynamically, saving operations later.
** i is the number of elements successfully pushed to B & shows what 
   the acceptable index range is
*/
static void	push_chunks_to_b(t_stack **a, t_stack **b, t_stats *stats)
{
	int	chunk_size;
	int	i;

	chunk_size = get_chunk_size(stack_size(*a));
	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b, stats);
			rb(b, stats);
			i++;
		}
		else if ((*a)->index <= i + chunk_size)
		{
			pb(a, b, stats);
			i++;
		}
		else
			ra(a, stats);
	}
}

/*			rb(b, stats); // Move smaller elements to the bottom of B

			ra(a, stats); // If it doesn't belong to the chunk, 
			rotate A to look for another
*/
/*
** Bring a specific index to the top of B.
** Use the direction requiring fewer rotations.
*/
static void	move_b_to_top(t_stack **b, int index, t_stats *stats)
{
	int	pos;
	int	size;

	pos = find_position(*b, index);
	size = stack_size(*b);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rb(b, stats);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rrb(b, stats);
			pos++;
		}
	}
}

/*
** Finds the maximum index remaining in stack B, rotates it to the top
** using the shortest path logic, and pushes it back to stack A.
*/

/*
Just push elements from B to A, largest index first.
*/

static void	push_back_to_a(t_stack **a, t_stack **b, t_stats *stats)
{
	int	max_idx;

	while (*b)
	{
		max_idx = find_max_index(*b);
		move_b_to_top(b, max_idx, stats);
		pa(a, b, stats);
	}
}

/*
** Main algorithm function for Medium stacks.
** 1. Empties stack A by sending elements pre-grouped by chunks into B.
** 2. Returns all elements from B back to A by always finding the maximum.
*/
void	sort_medium(t_stack **a, t_stack **b, t_stats *stats)
{
	if (a == NULL || *a == NULL || b == NULL || *b != NULL)
		return ;
	push_chunks_to_b(a, b, stats);
	push_back_to_a(a, b, stats);
}

/* static void	push_back_to_a(t_stack **a, t_stack **b, t_stats *stats)
{
	int	max_idx;
	//int	pos;
	//int	size;

	while (*b)
	{
		max_idx = find_max_index(*b);
		pos = find_position(*b, max_idx);
		size = stack_size(*b);
		// Bring the maximum element to the top of B using the fastest route
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				rb(b);
		}
		else
		{
			while (pos++ < size)
				rrb(b);
		}
		move_b_to_top(b, max_idx, stats);
		pa(a, b, stats); // Push it perfectly sorted back to A
	}
}*/