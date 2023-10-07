#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>


#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	int			nbr;
	struct s_stack	*next;
}					t_stack;


void	swap_a(t_stack **stack);
void	swap_b(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);


#endif
