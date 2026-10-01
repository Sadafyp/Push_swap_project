#include "push_swap.h"
/*
lines prefixed with [bench] represent messages printed by the optional bench-
mark mode (to stderr).
*/
static void	print_count(char *name, int count)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(count, 2);
	ft_putstr_fd("\n", 2);
}

static void	print_operation_stats(t_stats *stats)
{
	print_count("sa", stats->sa);
	print_count("sb", stats->sb);
	print_count("ss", stats->ss);
	print_count("pa", stats->pa);
	print_count("pb", stats->pb);
	print_count("ra", stats->ra);
	print_count("rb", stats->rb);
	print_count("rr", stats->rr);
	print_count("rra", stats->rra);
	print_count("rrb", stats->rrb);
	print_count("rrr", stats->rrr);
}

static void	print_strategy(t_strategy strategy)
{
	if (strategy == SIMPLE)
		ft_putstr_fd("Strategy: simple O(n^2)\n", 2);
	else if (strategy == MEDIUM)
		ft_putstr_fd("Strategy: medium O(n sqrt(n))\n", 2);
	else if (strategy == COMPLEX)
		ft_putstr_fd("Strategy: complex O(n log n)\n", 2);
}

void	print_stats(t_stats *stats, double disorder, t_strategy strategy)
{
	ft_putstr_fd("Disorder: ", 2);
	ft_putnbr_fd((int)(disorder * 100), 2);
	ft_putstr_fd("%\n", 2);
	print_strategy(strategy);
	ft_putstr_fd("Total operations: ", 2);
	ft_putnbr_fd(stats->total, 2);
	ft_putstr_fd("\n", 2);
	print_operation_stats(stats);
}