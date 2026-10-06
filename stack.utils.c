/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Natasha <Natasha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:31:35 by syazdanp          #+#    #+#             */
/*   Updated: 2026/10/04 20:32:46 by Natasha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include <stdio.h> /* for debugging purposes, remove later */

/*
** Allocates and initializes a new stack node with a value.
** The node index is initialized to -1, as it will be set later.
*/

t_stack	*stack_new(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

/*node->index = -1; index is initialized to -1, as it will be set later */

/* *stack is actually the head of the stack, while **stack is the pointer 
to the head (address of the head, using it we can change 
it so it points to the new head) */

t_stack	*stack_last(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/*
** Appends a new node to the back of the target stack.
*/

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
/* No need for a delete function here because we can only free 
the nodes as the node's value is not a pointer but an integer */

/*
** Clears all allocated nodes in the target stack and sets head to NULL.
*/

void	stack_clear(t_stack **stack)
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
