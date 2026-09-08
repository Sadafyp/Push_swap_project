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

void	move_to_top(t_stack **a, int index)
{
	int	position;
	int	size;

	position = find_position(*a, index);
	size = stack_size(*a);
	if (position <= size / 2) //which way to rotate is shorter, if position is in the first half of the stack, use ra, otherwise use rra
	{
		while (position > 0)
		{
			ra(a);
			position--;
		}
	}
	else
	{
		while (position < size)
		{
			rra(a);
			position++;
		}
	}
}

void	sort_simple(t_stack **a, t_stack **b)
{
	int	min;

	while (stack_size(*a) > 3)
	{
		min = find_min_index(*a);
		move_to_top(a, min);
		pb(a, b);
	}
	if (stack_size(*a) == 2)
		sort_two(a);
	else if (stack_size(*a) == 3)
		sort_three(a);
	while (*b)
		pa(a, b);
}