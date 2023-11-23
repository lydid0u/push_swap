/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jsp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:31:04 by lboudjel          #+#    #+#             */
/*   Updated: 2023/11/23 19:09:03 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_biggest_element(t_stack **stack)
{
	int		big;
	t_stack	*tmp;

	tmp = *stack;
	big = (*stack)->nbr;
	if (*stack == NULL)
		return (0);
	while (tmp)
	{
		if (big < tmp->nbr)
			big = tmp->nbr;
		tmp = tmp->next;
	}
	return (big);
}

int	where_is_the_smallest(t_stack *stack)
{
	t_stack	*current_stack;
	t_stack	*smallest;
	int		i;
	int		j;

	current_stack = stack;
	smallest = stack;
	i = 0;
	j = 0;
	while (current_stack)
	{
		if (smallest->nbr > current_stack->nbr)
		{
			j = i;
			smallest = current_stack;
		}
		current_stack = current_stack->next;
		i++;
	}
	return (j);
}

t_stack	**mv_smol_up_v2(t_stack **stack)
{
	int	smollest_id;
	int	size;

	smollest_id = find_position(*stack, find_smol(stack));
	size = ft_stack_size(*stack);
	if (smollest_id <= size / 2)
		while (((*stack)->nbr) != find_smol(stack))
			rotate_a(stack);
	else
		while (((*stack)->nbr) != find_smol(stack))
			r_rotate_a(stack);
	return (stack);
}
