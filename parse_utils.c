#include "push_swap.h"

/* t_stack * when the function only needs to read/traverse the stack;
t_stack ** when the function may need to change the head pointer itself.*/

int	parse_number(const char *str, int *value)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;

	if (!str || !str[0])
		return(0);
	if (str[i] == '-' || str[i] == '+')
	{	
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return(0);
	while(str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		nbr = nbr * 10 + (str[i] - '0');
		if (sign * nbr > INT_MAX
			|| sign * nbr < INT_MIN)
			return (0);
		i++;
	}
	*value = (int)(sign * nbr);
	return(1);
}
/*For boolean-style functions:
1 = true
0 = false
For success/failure functions:
1 = success
0 = failure*/

int	is_duplicate(t_stack *stack, int value)
{
	while(stack != NULL)
	{
		if(stack->value == value)
			return(1);
		stack = stack->next;
	}
	return(0);
}

int parser(int argc, char **argv, t_stack **stack)
{
	int	i;
	int	value;
	t_stack	*new;

	i = 1;
	while(i < argc)
	{
		if(!parse_number(argv[i], &value))
			return(0);
		if(is_duplicate(*stack, value))
			return(0);
		new = stack_new(value);
		if(new == NULL)
			return(0);
		stack_add_back(stack, new);
		i++;
	}
	return(1);
}