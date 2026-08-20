#include "push_swap.h"

void op_swap(t_stack **stack)
{
	t_stack *first;
	t_stack	*second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void sa(t_stack **a)
{
	op_swap(a);
	ft_putstr_fd("sa\n", 1); /*standard output ->1 */
}

void sb(t_stack **b)
{
	op_swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	op_swap(a);
	op_swap(b);
	ft_putstr_fd("ss\n", 1);
}