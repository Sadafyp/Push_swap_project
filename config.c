/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 17:52:32 by syazdanp          #+#    #+#             */
/*   Updated: 2026/10/06 17:58:53 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
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
*/

void	sort_stack(t_stack **a, t_stack **b, t_stats *stats,
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

int	parse_flag(char *arg, t_config *config)
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

int	parse_flags(int argc, char **argv, t_config *config)
{
	int	i;

	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (!parse_flag(argv[i], config))
			return (-1);
		i++;
	}
	return (i);
}

t_strategy	select_adaptive(double disorder)
{
	if (disorder < 0.2)
		return (SIMPLE);
	if (disorder < 0.5)
		return (MEDIUM);
	return (COMPLEX);
}

int	init_stack(int argc, char **argv, t_stack **a,
		t_config *config)
{
	int	start;

	*a = NULL;
	config->strategy = ADAPTIVE;
	config->bench = 0;
	start = parse_flags(argc, argv, config);
	if (start == -1 || start == argc)
		return (0);
	if (!parser(argc, argv, start, a))
		return (0);
	return (1);
}
