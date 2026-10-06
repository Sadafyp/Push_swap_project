/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Natasha <Natasha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:31:35 by syazdanp          #+#    #+#             */
/*   Updated: 2026/10/04 20:34:53 by Natasha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include <stdio.h> /* for debugging purposes, remove later */

/*
** Returns 1 if the stack elements are already sorted in ascending order.
*/

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

/*
** Counts and returns the absolute number of nodes present inside the stack.
*/

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

/*
** Iterates through the stack to calculate and assign relative rank indices.
*/

void	assign_index(t_stack *stack)
{
	int		index;
	t_stack	*current;
	t_stack	*temp;

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
		current->index = index;
		current = current->next;
	}
}

/*printf("index %d --- value %d\n", index, current->value);
Debugging line to check the assigned index */