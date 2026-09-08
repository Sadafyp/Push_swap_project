#include "push_swap.h"

void op_reverse_rotate(t_stack **stack)
{
	t_stack *before_last;
	t_stack *last;

	if (stack ==NULL || *stack == NULL || (*stack)->next ==NULL)
		return;
	last = stack_last(*stack);
	before_last = *stack;
	while (before_last->next != last)
		before_last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void rra(t_stack **a)
{
	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return;
	op_reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void rrb(t_stack **b)
{
	if (b == NULL || *b == NULL || (*b)->next == NULL)
		return;
	op_reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void rrr(t_stack **a, t_stack **b)
{
	if ((a == NULL || *a == NULL || (*a)->next == NULL) && (b == NULL || *b == NULL || (*b)->next == NULL))
		return;
	op_reverse_rotate(a);
	op_reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}