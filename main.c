/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:31:35 by syazdanp          #+#    #+#             */
/*   Updated: 2026/10/06 17:53:04 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_stats		stats;
	t_config	config;
	double		disorder;

	if (argc == 1)
		return (0);
	b = NULL;
	stats = (t_stats){0};
	if (!init_stack(argc, argv, &a, &config))
		return (ft_putstr_fd("Error\n", 2), stack_clear(&a), 1);
	assign_index(a);
	disorder = compute_disorder(a);
	if (config.strategy == ADAPTIVE)
		config.strategy = select_adaptive(disorder);
	sort_stack(&a, &b, &stats, config.strategy);
	if (config.bench)
		print_stats(&stats, disorder, config.strategy);
	if (config.count_only)
		ft_putnbr_fd(stats.count_only, 1);
	return (stack_clear(&a), stack_clear(&b), 0);
}
