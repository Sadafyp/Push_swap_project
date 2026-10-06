/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_nat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Natasha <Natasha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:31:35 by syazdanp          #+#    #+#             */
/*   Updated: 2026/10/04 19:19:34 by Natasha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	parse_flags(int argc, char **argv, t_config *config)
{
	int	i;

	i = 1;
	while (i < argc && argv[i] == '-' && argv[i] == '-')
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

/* main Natasha */
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

/*
** HISTORICAL COMPANION NOTE:
** Old test mains, stack printing debuggers (print_stack), and old logic
** variants with manual operations (pb, pa, sa verification) have been 
** archived from this section to satisfy strict Norminette compilation rules.
*/
