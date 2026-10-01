#include "push_swap.h"
/*
repeatedly find the smallest remaining element
Bring it to top  ra or rra
move it to B pb
When only three elements remain in A, sort those three, then push everything back to A pa
 */

int find_position(t_stack *stack, int index)
{
	int position;
	position = 0;
	while (stack)
	{
		if (stack->index == index)
			return (position);
		position++;
		stack = stack->next;	
	}
	return (-1); /* index not found in the stack */
}

static void	move_a_to_top(t_stack **a, int index, t_stats *stats)
{
	int	position;
	int	size;

	position = find_position(*a, index);
	size = stack_size(*a);
	if (position <= size / 2) //which way to rotate is shorter, if position is in the first half of the stack, use ra, otherwise use rra
	{
		while (position > 0)
		{
			ra(a, stats);
			position--;
		}
	}
	else
	{
		while (position < size)
		{
			rra(a, stats);
			position++;
		}
	}
}

void	sort_simple(t_stack **a, t_stack **b, t_stats *stats)
{
	int	min;

	while (stack_size(*a) > 3)
	{
		min = find_min_index(*a);
		move_a_to_top(a, min, stats);
		pb(a, b, stats);
	}
	if (stack_size(*a) == 2)
		sort_two(a, stats);
	else if (stack_size(*a) == 3)
		sort_three(a, stats);
	while (*b)
		pa(a, b, stats);
	ft_printf("At the end of sort_simple, stack A is:\n");
}