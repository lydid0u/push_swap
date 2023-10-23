#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}					t_stack;

//					command					//
void				swap_a(t_stack **stack);
void				swap_b(t_stack **stack);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				push_a(t_stack **stack_a, t_stack **stack_b);
void				push_b(t_stack **stack_a, t_stack **stack_b);
void				rotate_a(t_stack **stack_a);
void				rotate_b(t_stack **stack_a);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				r_rotate_a(t_stack **stack_a);
void				r_rotate_b(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

//utils
t_stack				*get_last_node(t_stack *stack);
int					ft_atoi(char *str);
int					ft_list_size(t_stack *stack_a);
int					check_doubles(t_stack *stack_a);

//parsing
t_stack				create_node(t_stack *stack_a, char **argv);
t_stack				*ft_lstnew(void *nbr);

#endif