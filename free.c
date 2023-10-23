#include "push_swap.h"

void	free_node(t_stack *stack_a)
{
	t_stack	*stack;
	t_stack	*nxt;

	stack = stack_a;
	while (stack != NULL)
	{
		nxt = stack->next;
		free(stack);
		stack = nxt;
	}
}

void	free_tab(char **argv)
{
	int	i;

	i = 0 ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

