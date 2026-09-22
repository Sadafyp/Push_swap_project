# include "push_swap.h"

double compute_disorder(t_stack *stack)
{
	t_stack *first;
	t_stack *second;
	long pair_count;
	long mistakes;

	pair_count = 0;
	mistakes = 0;
	first = stack;
	while (first && first->next)
	{
		second = first->next;
		while(second)
		{
			pair_count++;
			if (first->value > second->value)
				mistakes++;
			second = second->next;
		}
		first = first->next;
	}
	if (pair_count == 0)
		return 0.0;
	return ((double)mistakes / (double)pair_count);
}