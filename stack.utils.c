#include "push_swap.h"
#include <stdio.h> /* for debugging purposes, remove later */

t_stack	*stack_new(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->index = -1; /* index is initialized to -1, as it will be set later */
	node->next = NULL;
	return (node);
}

t_stack	*stack_last(t_stack *stack) /* *stack is actually the head of the stack, while **stack is the pointer to the head (address of the head, using it we can change it so it points to the new head) */
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (stack == NULL || new == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = stack_last(*stack);
	last->next = new;
}

void	stack_clear(t_stack **stack) /* No need for a delete function here because we can only free the nodes as the node's value is not a pointer but an integer */
{
	t_stack	*next;

	if (stack == NULL)
		return ;
	while (*stack)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void assign_index(t_stack *stack)
{
	int index;
	t_stack *current;
	t_stack *temp;
	
	current = stack;
	while (current)
	{
		index = 0;
		temp = stack;
		while (temp)
		{
			if (temp->value < current->value)
				index++;
			temp = temp->next;
		}
		printf("index %d --- value %d\n", index, current->value); /* Debugging line to check the assigned index */
		current->index = index;
		current = current->next;
	}
}
