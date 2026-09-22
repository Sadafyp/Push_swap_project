#include "push_swap.h"

/*
** Returns the ideal chunk size based on the total amount of numbers.
** For 100 numbers, 4-5 chunks are recommended (chunk size ~20-25).
** For 500 numbers, 9-11 chunks are recommended (chunk size ~45-50).
*/
static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (22);
	return (48);
}

/*
** Pushes numbers from stack A to stack B by dividing them into chunks.
** If the current element's index belongs to the active chunk, it is sent to B (pb).
** Optimization: if the index is in the lower half of the chunk, we rotate B (rb)
** to pre-sort stack B dynamically, saving operations later.
*/
static void	push_chunks_to_b(t_stack **a, t_stack **b)
{
	int	chunk_size;
	int	i;

	chunk_size = get_chunk_size(stack_size(*a));
	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			rb(b); // Move smaller elements to the bottom of B
			i++;
		}
		else if ((*a)->index <= i + chunk_size)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a); // If it doesn't belong to the chunk, rotate A to look for another
	}
}

/*
** Finds the maximum index remaining in stack B, rotates it to the top
** using the shortest path logic, and pushes it back to stack A.
*/
static void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	max_idx;
	int	pos;
	int	size;

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
		pa(a, b); // Push it perfectly sorted back to A
	}
}

/*
** Main algorithm function for large stacks.
** 1. Empties stack A by sending elements pre-grouped by chunks into B.
** 2. Returns all elements from B back to A by always finding the maximum.
*/
void	sort_large(t_stack **a, t_stack **b)
{
	push_chunks_to_b(a, b);
	push_back_to_a(a, b);
}
