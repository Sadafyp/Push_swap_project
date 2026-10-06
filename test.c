/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 16:10:57 by syazdanp          #+#    #+#             */
/*   Updated: 2026/10/06 16:10:58 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
/*static void	print_stack(char *name, t_stack *stack)
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
}*/
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
		stack_clear(&a); //anytime an input returns error, 
		it should clean up: 6 7 8 Hello
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

static void	sort_stack(t_stack **a, t_stack **b, t_stats *stats,
	t_strategy strategy)
{
	if (is_sorted(*a))
		return ;
	if (stack_size(*a) == 2)
		sort_two(a, stats);
	else if (stack_size(*a) == 3)
		sort_three(a, stats);
	else if (strategy == SIMPLE)
		sort_simple(a, b, stats);
	else if (strategy == MEDIUM)
		sort_medium(a, b, stats);
	else if (strategy == COMPLEX)
		sort_complex(a, b, stats);
}
/*
static int	check_bench(int argc, char **argv, t_stats *stats)
{
	if (argc > 1 && ft_strncmp(argv[1], "--bench", 8) == 0)
	{
		stats->bench = 1;
		return (2);
	}
	return (1);
}
*/

static int	parse_flag(char *arg, t_config *config)
{
	if (ft_strncmp(arg, "--bench", 8) == 0)
		config->bench = 1;
	else if (ft_strncmp(arg, "--simple", 9) == 0)
		config->strategy = SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		config->strategy = MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		config->strategy = COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		config->strategy = ADAPTIVE;
	else
		return (0);
	return (1);
}
/*if there are multiple flags, for example: --simple --bench */

static int	parse_flags(int argc, char **argv, t_config *config)
{
	int	i;

	i = 1;
	while (i < argc && argv[i][0] == '-'
		&& argv[i][1] == '-')
	{
		if (!parse_flag(argv[i], config))
			return (-1);
		i++;
	}
	return (i);
}

static t_strategy	select_adaptive(double disorder)
{
	if (disorder < 0.2)
		return (SIMPLE);
	if (disorder < 0.5)
		return (MEDIUM);
	return (COMPLEX);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_stats		stats;
	t_config	config;
	int			start;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	ft_bzero(&stats, sizeof(t_stats));
	config = (t_config){ADAPTIVE, 0};
	start = parse_flags(argc, argv, &config);
	if (start == -1 || start == argc || !parser(argc, argv, start, &a))
		return (ft_putstr_fd("Error\n", 2), stack_clear(&a), 1);
	assign_index(a);
	if (stack_size(a) <= 5)
		config.strategy = SIMPLE;
	else if (config.strategy == ADAPTIVE)
		config.strategy = select_adaptive(compute_disorder(a));
	sort_stack(&a, &b, &stats, config.strategy);
	if (config.bench)
		print_stats(&stats, compute_disorder(a), config.strategy);
	return (stack_clear(&a), stack_clear(&b), 0);
}

/*int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_stats		stats;
	t_config	config;
	t_strategy	strategy;
	double		disorder;
	int			start;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	stats = (t_stats){0};
	config.strategy = ADAPTIVE;
	config.bench = 0;
	start = parse_flags(argc, argv, &config);
	if (start == -1 || start == argc) // both ./a.out --hello 5 3 1 
	and ./a.out --bench are unaccepted
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (!parser(argc, argv, start, &a))
	{
		ft_putstr_fd("Error\n", 2);
		stack_clear(&a);
		return (1);
	}
	print_stack("A before sorting", a);
	print_stack("B before sorting", b);
	assign_index(a);
	disorder = compute_disorder(a);
	strategy = config.strategy;
	if (strategy == ADAPTIVE)
		strategy = select_adaptive(disorder);
	sort_stack(&a, &b, &stats, strategy); // Sort the stack based on 
	the selected strategy, disorder doesn't matter
	if (config.bench)
		print_stats(&stats, disorder, strategy);
	print_stack("A after sorting", a);
	print_stack("B after sorting", b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}*/