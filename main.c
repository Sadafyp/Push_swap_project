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

static void	print_stack(char *name, t_stack *stack)
{
	ft_printf("%s: ", name);
	while (stack)
	{
		ft_printf("%d", stack->value);
		if (stack->next)
			ft_printf(" -> ");
		stack = stack->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
	//t_stack	*current;

	a = NULL;
	b = NULL;
	if (!parser(argc, argv, &a))
	{
		ft_putstr_fd("Error\n", 2);
		stack_clear(&a); /*anytime an input returns error, it should clean up: 6 7 8 Hello */
		return (1);
	}
	print_stack("A before", a);
	print_stack("B before", b);
	/* sa(&a);
	current = a;
	while (current)
	{
		ft_printf("value = %d, index = %d\n",
			current->value, current->index);
		current = current->next;
	}*/
	pb(&a, &b);

	print_stack("A after pb", a);
	print_stack("B after pb", b);
	
	pb(&a, &b);

	print_stack("A after pb", a);
	print_stack("B after pb", b);

	pb(&a, &b);

	print_stack("A after pb", a);
	print_stack("B after pb", b);

	pa(&a, &b);

	print_stack("A after pa", a);
	print_stack("B after pa", b);

	stack_clear(&a);
	stack_clear(&b);
	return (0);
}