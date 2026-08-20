#include "push_swap.h"
/*
int	main(void)
{
	t_stack	*a;
	t_stack	*current;

	a = NULL;
	stack_add_back(&a, stack_new(5));
	stack_add_back(&a, stack_new(2));
	stack_add_back(&a, stack_new(8));
	stack_add_back(&a, stack_new(1));
	current = a;
	while (current)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
	stack_clear(&a);
	return (0);
}
*/


int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*current;

	a = NULL;
	if (!parser(argc, argv, &a))
	{
		ft_putstr_fd("Error\n", 2);
		stack_clear(&a); /*anytime an input returns error, it should clean up 6 7 8 Hello */
		return (1);
	}
	sa(&a);
	current = a;
	while (current)
	{
		ft_printf("value = %d, index = %d\n",
			current->value, current->index);
		current = current->next;
	}
	stack_clear(&a);
	return (0);
}