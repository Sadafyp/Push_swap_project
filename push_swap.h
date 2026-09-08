#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include <limits.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"


typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}t_stack;

t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_clear(t_stack **stack);
int		parse_number(const char *str, int *value);
int		is_duplicate(t_stack *stack, int value);
int		parser(int argc, char **argv, t_stack **stack);
void	op_push(t_stack **src, t_stack **dest);
void	op_swap(t_stack **stack);
void	op_rotate(t_stack **stack);
void	op_reverse_rotate(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	assign_index(t_stack *stack);
int		is_sorted(t_stack *stack);
int 	stack_size(t_stack *stack);
int		find_max_index(t_stack *stack);
int		find_min_index(t_stack *stack);
int		find_position(t_stack *stack, int index);
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	sort_simple(t_stack **a, t_stack **b);
void	move_to_top(t_stack **a, int index);



#endif