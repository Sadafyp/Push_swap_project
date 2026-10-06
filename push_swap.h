/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syazdanp <syazdanp@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:31:35 by syazdanp          #+#    #+#             */
/*   Updated: 2026/10/06 18:54:42 by syazdanp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stats
{
	int	total;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_stats;

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_config
{
	t_strategy	strategy;
	int			bench;
}	t_config;

t_stack		*stack_new(int value);
t_stack		*stack_last(t_stack *stack);
void		stack_add_back(t_stack **stack, t_stack *new);
void		stack_clear(t_stack **stack);
int			parse_number(const char *str, int *value);
int			is_duplicate(t_stack *stack, int value);
int			parser(int argc, char **argv, int start, t_stack **stack);
void		op_push(t_stack **src, t_stack **dest);
void		op_swap(t_stack **stack);
void		op_rotate(t_stack **stack);
void		op_reverse_rotate(t_stack **stack);
void		sa(t_stack **a, t_stats *stats);
void		sb(t_stack **b, t_stats *stats);
void		ss(t_stack **a, t_stack **b, t_stats *stats);
void		pa(t_stack **a, t_stack **b, t_stats *stats);
void		pb(t_stack **a, t_stack **b, t_stats *stats);
void		ra(t_stack **a, t_stats *stats);
void		rb(t_stack **b, t_stats *stats);
void		rr(t_stack **a, t_stack **b, t_stats *stats);
void		rra(t_stack **a, t_stats *stats);
void		rrb(t_stack **b, t_stats *stats);
void		rrr(t_stack **a, t_stack **b, t_stats *stats);
void		assign_index(t_stack *stack);
int			is_sorted(t_stack *stack);
int			stack_size(t_stack *stack);
int			find_max_index(t_stack *stack);
int			find_min_index(t_stack *stack);
int			find_position(t_stack *stack, int index);
void		sort_two(t_stack **a, t_stats *stats);
void		sort_three(t_stack **a, t_stats *stats);
void		sort_simple(t_stack **a, t_stack **b, t_stats *stats);
void		sort_medium(t_stack **a, t_stack **b, t_stats *stats);
double		compute_disorder(t_stack *stack);
void		sort_complex(t_stack **a, t_stack **b, t_stats *stats);
void		print_stats(t_stats *stats, double disorder, t_strategy strategy);
void		sort_stack(t_stack **a, t_stack **b, t_stats *stats,
				t_strategy strategy);
int			parse_flag(char *arg, t_config *config);
int			parse_flags(int argc, char **argv, t_config *config);
int			init_stack(int argc, char **argv, t_stack **a, t_config *config);
t_strategy	select_adaptive(double disorder);

#endif
