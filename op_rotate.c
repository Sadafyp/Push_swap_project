# include "push_swap.h"
/*
ra : The first element of stack A becomes the last one. Shift all elements by one.
rb : The first element of stack B becomes the last one. Shift all elements by one.
rr : ra and rb at the same time.
*/

void op_rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = first->next;
	last = stack_last(*stack);
	last->next = first;
	first->next = NULL;
}

void ra(t_stack **a)
{
	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	op_rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void rb(t_stack **b)
{
	if (b == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	op_rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void rr(t_stack **a, t_stack **b)
{
	if ((a == NULL || *a == NULL || (*a)->next == NULL) && (b == NULL || *b == NULL || (*b)->next == NULL))
		return ;
	op_rotate(a);
	op_rotate(b);
	ft_putstr_fd("rr\n", 1);
}