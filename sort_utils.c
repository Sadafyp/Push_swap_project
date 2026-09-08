#include "push_swap.h"

void sort_two(t_stack **a)
{
	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	if ((*a)->index > (*a)->next->index)
		sa(a);
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

int find_min_index(t_stack *stack)
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

void sort_three(t_stack **a)
{
	int	max_index;

	if (is_sorted(*a))
		return ;
	max_index = find_max_index(*a);
	if ((*a)->index == max_index)
		ra(a);
	else if ((*a)->next->index == max_index)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}