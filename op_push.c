#include "push_swap.h"
/*
pa: take the top of B and put it on top of A
pb: take the top of A and put it on top of B
*/

void	op_push(t_stack	**src, t_stack **dest) 
{
	t_stack	*head;

	if (src == NULL || *src == NULL || dest == NULL)
		return ;
	head = *src;
	*src = (*src)->next;
	head->next = *dest;
	*dest = head;
}