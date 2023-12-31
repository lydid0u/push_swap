/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:25:07 by lboudjel          #+#    #+#             */
/*   Updated: 2023/11/23 19:24:45 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	each_case(t_stack **stack_a, t_stack **stack_b)
{
	int	list;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return (0);
	list = ft_stack_size(*stack_a);
	if (in_order(stack_a))
		return (0);
	else if (list == 2)
		swap_a(stack_a);
	else if (list == 3)
		sort_three(stack_a);
	else if (list == 4)
		sort_four(stack_a, stack_b);
	else if (list == 5)
		sort_five(stack_a, stack_b);
	else
	{
		push_to_pile_b(stack_a, stack_b);
		sort_three(stack_a);
		sorting(stack_a, stack_b);
		mv_smol_up_v2(stack_a);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	(void)stack_b;
	(void)argv;
	if (argc == 1)
		return (ft_printf("Error2\n"), 0);
	else if (argc == 2)
	{
		in_quote(&stack_a, argv[1]);
		if (check_doubles(stack_a) == 0 || ft_stack_size(stack_a) == 0)
			return (free_node(stack_a), ft_printf("Error22\n"), 0);
	}
	else if (argc > 2)
	{
		if (nbr_listed(&stack_a, argc, argv) == 0)
			return (0);
		if (check_doubles(stack_a) == 0 || ft_stack_size(stack_a) == 0)
			return (free_node(stack_a), ft_printf("Error2\n"), 0);
	}
	each_case(&stack_a, &stack_b);
	free_node(stack_a);
	return (1);
}
