#include "push_swap.h"

t_stack	**sort_three(t_stack **stack_a)
{
	int	nxt;
	int	nxt_nxt;

	nxt = (*stack_a)->next->nbr;
	nxt_nxt = (*stack_a)->next->next->nbr;
	if (*stack_a == NULL || (*stack_a)->next == NULL || (*stack_a)->next->next == NULL)
		return NULL;
	if ((*stack_a)->nbr > nxt && nxt < nxt_nxt && (*stack_a)->nbr < nxt_nxt)
		swap_a(stack_a);
	else if ((*stack_a)->nbr > nxt && nxt < nxt_nxt && (*stack_a)->nbr > nxt_nxt)
		rotate_a(stack_a);
	else if ((*stack_a)->nbr < nxt && nxt > nxt_nxt && (*stack_a)->nbr > nxt_nxt)
		r_rotate_a(stack_a);
	else if ((*stack_a)->nbr < nxt && nxt > nxt_nxt && (*stack_a)->nbr < nxt_nxt)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if ((*stack_a)->nbr > nxt && nxt > nxt_nxt && (*stack_a)->nbr > nxt_nxt)
	{
		swap_a(stack_a);
		r_rotate_a(stack_a);
	}
	return (stack_a);
}
