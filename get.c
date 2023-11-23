/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:31:04 by lboudjel          #+#    #+#             */
/*   Updated: 2023/11/21 12:33:10 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_content(t_stack *stack)
{
	t_stack	*current;
	int		min;

	current = stack;
	min = 2147483647;
	while (current)
	{
		if (current->nbr < min)
			min = current->nbr;
		current = current->next;
	}
	return (min);
}

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

int	get_max_content(t_stack *stack)
{
	t_stack	*current;
	int		max;

	current = stack;
	max = 0;
	while (current)
	{
		if (current->nbr > max)
			max = current->nbr;
		current = current->next;
	}
	return (max);
}

int	get_min_pos(t_stack *stack)
{
	t_stack	*current;
	t_stack	*min_node;
	int		i;
	int		j;

	current = stack;
	min_node = stack;
	i = 0;
	j = 0;
	while (current)
	{
		if (min_node->nbr > current->nbr)
		{
			j = i;
			min_node = current;
		}
		current = current->next;
		i++;
	}
	return (j);
}

void	put_min_top(t_stack **stack)
{
	if (get_min_pos(*stack) <= ft_stack_size(*stack) / 2)
	{
		while (get_min_pos(*stack) != 0)
			rotate_a(stack);
	}
	else
	{
		while (get_min_pos(*stack) != 0)
			r_rotate_a(stack);
	}
}
