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

t_stack	**sort_four(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL)
		return (NULL);
	*stack_a = mv_smol_up(*stack_a);
	push_b(stack_a, stack_b);
	sort_three(stack_a);
	push_a(stack_b, stack_a);
	return (stack_a);
}

t_stack	**sort_five(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL)
		return (NULL);
	*stack_a = mv_smol_up(*stack_a);
	push_b(stack_a, stack_b);
	*stack_a = mv_smol_up(*stack_a);
	push_b(stack_a, stack_b);
	sort_three(stack_a);
	push_a(stack_b, stack_a);
	push_a(stack_b, stack_a);
	return (stack_a);
}

int		find_smol(t_stack **stack)
{
	int		smol;
	t_stack	*now;

	if (stack == NULL)
		return (0);
	now = *stack;
	smol = (*stack)->nbr;
	if (*stack == NULL)
		return (0);
	while (now != NULL)
	{
		if (smol > now->nbr)
			smol = now->nbr;
		now = now->next;
	}
	return (smol);
}

t_stack	*mv_smol_up(t_stack *stack)
{
	int	smollest_id;
	int	size;

	smollest_id = find_index(stack, find_smol(&stack));
	size = ft_list_size(stack);
	if (smollest_id <= size / 2)
		while (stack->nbr != find_smol(&stack))
			rotate_a(&stack);
	else
		while (stack->nbr != find_smol(&stack))
			r_rotate_a(&stack);
	return (stack);
}