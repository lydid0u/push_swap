/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:50:05 by lboudjel          #+#    #+#             */
/*   Updated: 2023/11/23 17:00:40 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	targeted(t_stack *stack, int content)
{
	t_stack	*current;
	t_stack	*prev;
	int		i;
	int		index;

	current = stack;
	prev = get_last_node(stack);
	i = 0;
	index = 0;
	if (content > find_biggest_element(&stack) || content < find_smol(&stack))
		return (where_is_the_smallest(stack));
	while (current)
	{
		if (content < current->nbr && content > prev->nbr)
			index = i;
		i++;
		prev = current;
		current = current->next;
	}
	return (index);
}

void	finding_the_one_to_move(t_stack **stack_a, t_stack **stack_b, int *tab,
		int i)
{
	t_stack	*current_stack;
	int		total;
	int		max;
	int		to_move_to_a;
	int		to_move_to_b;

	i = 0;
	max = 2147483647;
	current_stack = *stack_b;
	while (current_stack)
	{
		to_move_to_a = cost_definer_b(ft_stack_size(*stack_a),
				targeted(*stack_a, current_stack->nbr));
		to_move_to_b = cost_definer_a(*stack_b, i);
		total = total_cost(to_move_to_a, to_move_to_b);
		if (max > total)
		{
			max = total;
			tab[0] = to_move_to_b;
			tab[1] = to_move_to_a;
		}
		i++;
		current_stack = current_stack->next;
	}
}

int	total_cost(int to_move_to_a, int to_move_to_b)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (to_move_to_a < 0)
		a = to_move_to_a * -1;
	else if (to_move_to_a > 0)
		a = to_move_to_a;
	if (to_move_to_b < 0)
		b = to_move_to_b * -1;
	else if (to_move_to_b > 0)
		b = to_move_to_b;
	if ((to_move_to_a < 0 && to_move_to_b < 0)
		|| (to_move_to_a > 0 && to_move_to_b > 0))
	{
		if (a >= b)
			return (a);
		return (b);
	}
	return (a + b);
}

int	cost_definer_a(t_stack *stack_b, int position)
{
	int	sizelist_a;
	int	cost;

	sizelist_a = ft_stack_size(stack_b);
	if (position > sizelist_a / 2)
		cost = sizelist_a - position;
	else
		cost = -position;
	return (cost);
}

int	cost_definer_b(int sizelist, int position)
{
	int	cost;

	if (position > sizelist / 2)
		cost = sizelist - position;
	else
		cost = -position;
	return (cost);
}
