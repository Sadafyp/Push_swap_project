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
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	while (stack)
	{
		ft_putnbr_fd(stack->value, 2);
		if (stack->next)
			ft_putstr_fd(" -> ", 2);
		stack = stack->next;
	}
	ft_putstr_fd("\n", 2);
}
/*
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
		stack_clear(&a); //anytime an input returns error, it should clean up: 6 7 8 Hello
		return (1);
	}
	print_stack("A before", a);
	print_stack("B before", b);
	*/
	/* sa(&a);
	current = a;
	while (current)
	{
		ft_printf("value = %d, index = %d\n",
			current->value, current->index);
		current = current->next;
	}*/
	/*
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
	*/
/*
	assign_index(a);
	if (is_sorted(a))
		;
	else if (stack_size(a) == 2)
		sort_two(&a);
	else if (stack_size(a) == 3)
		sort_three(&a);
	else if (stack_size(a) == 4 || stack_size(a) == 5)
	{
		ft_printf("here\n");
		ft_printf("disorder = %d%%\n",(int)(compute_disorder(a) * 100));
		sort_simple(&a, &b); 
	}
	else	
		sort_medium(&a, &b);  
	print_stack("A after sorting", a);
	print_stack("B after sorting", b);

	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
*/
// ----------CLEANED UP MAIN------------------

static void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	if (is_sorted(*a))
		return ;
	size = stack_size(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_simple(a, b);
	else
		sort_medium(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	if (!parser(argc, argv, &a))
	{
		ft_putstr_fd("Error\n", 2);
		stack_clear(&a);
		return (1);
	}
	print_stack("A before sorting", a);
	print_stack("B before sorting", b);
	assign_index(a);
	sort_stack(&a, &b);
	print_stack("A after sorting", a);
	print_stack("B after sorting", b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}