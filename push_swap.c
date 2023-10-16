#include "push_swap.h"


int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	(void)argv;
	if (argc < 2)
		return (ft_printf("Error\n"), 0);
	if (argc == 2)
		return 1;
		// split;
	if (argc > 2)
		return 1;
		// checkint;
}