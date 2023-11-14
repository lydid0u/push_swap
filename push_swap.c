/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzinabi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:25:07 by lboudjel          #+#    #+#             */
/*   Updated: 2023/11/13 15:29:09 by adzinabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printf_lst_target(t_stack *pile_a)
{
	t_stack	*tmp;

	tmp = pile_a;
	printf("liste target : \n");
	while (tmp)
	{
		ft_printf("%d\n", tmp->target);
		tmp = tmp->next;
	}
	printf("\n\n\n\n");
}

int	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	list;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return (0);
	list = ft_list_size(*stack_a);
	if (in_order(stack_a))
		return (free_node(*stack_a), ft_printf("Error\nStack is ordered"), 0);
	else if (list == 2)
		swap_a(stack_a);
	else if (list == 3)
		sort_three(stack_a);
	else if (list == 4)
	{
		sort_four(stack_a, stack_b);
		print_stack(*stack_a);
		print_stack(*stack_b);
	}
	else if (list == 5)
	{
		sort_five(stack_a, stack_b);
		print_stack(*stack_a);
		print_stack(*stack_b);
	}
	else
	{
		if (ft_list_size(*stack_b) == 3 && in_order(stack_b) == 0)
			sort_three(stack_b);
		print_stack(*stack_a);
		index_definer_second_half(*stack_a);
		index_definer_second_half(*stack_b);
		where_am_i(*stack_a);
		where_am_i(*stack_b);
		print_index(*stack_a);
		print_index(*stack_b);
		target_finder(*stack_a, *stack_b);
		printf_lst_target(*stack_a);
		cost_finder(*stack_a, *stack_b);
		targeted_and_targeting_at_the_top(*stack_a, *stack_b);
		// print_stack(*stack_a);
		// print_stack(*stack_b);
		// print_stack(*stack_b);
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
	if (argc < 2)
		return (ft_printf("Error1\n"), 0);
	else if (argc == 2)
	{
		in_quote(&stack_a, argv[1]);
		if (check_doubles(stack_a) == 0 || ft_list_size(stack_a) == 1)
			return (free_node(stack_a), ft_printf("Error2\n"), 0);
		push_b(&stack_a, &stack_b);
		push_b(&stack_a, &stack_b);
		push_b(&stack_a, &stack_b);
	}
	else if (argc > 2)
	{
		if (nbr_listed(&stack_a, argc, argv) == 0)
			return (0);
		if (check_doubles(stack_a) == 0 || ft_list_size(stack_a) == 1)
			return (free_node(stack_a), ft_printf("Error4\n"), 0);
		push_b(&stack_a, &stack_b);
		push_b(&stack_a, &stack_b);
		push_b(&stack_a, &stack_b);
	}
	algorithm(&stack_a, &stack_b);
	return (1);
}
