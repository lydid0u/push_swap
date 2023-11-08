/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:50:05 by lboudjel          #+#    #+#             */
/*   Updated: 2023/11/06 16:21:16 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_definer_second_half(t_stack *stack)
{
	int		sizelist;
	int		i;
	t_stack	*current;

	current = stack;
	sizelist = ft_list_size(current);
	i = (sizelist / 2);
	index_definer_first_half(current);
	while (current)
	{
		current = current->next;
		if (current->index == i)
		{
			if (sizelist % 2 != 0)
			{
				current = current->next;
				current->index = i;
			}
			break ;
		}
	}
	while (i >= 0 && current)
	{
		current->index = i;
		i--;
		current = current->next;
	}
}

void	index_definer_first_half(t_stack *stack)
{
	int		sizelist;
	int		i;
	int		j;
	t_stack	*current;

	j = 0;
	current = stack;
	sizelist = ft_list_size(stack);
	i = (sizelist / 2);
	while (i >= 0 && current)
	{
		current->index = j;
		current = current->next;
		j++;
		i--;
	}
}

int	find_smallest_element(t_stack **stack)
{
	int		small;
	t_stack	*tmp;

	tmp = *stack;
	small = (*stack)->nbr;
	if (*stack == NULL)
		return (0);
	while (tmp)
	{
		if (small > tmp->nbr)
			small = tmp->nbr;
		tmp = tmp->next;
	}
	return (small);
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
// guette le code comment il est trop beau // nique ta race

void	target_finder(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_stack_a;
	t_stack	*current_stack_b;
	int		best_match;

	current_stack_a = stack_a;
	while (current_stack_a)
	{
		current_stack_b = stack_b;
		best_match = INT_MAX;
		while (current_stack_b)
		{
			if (current_stack_a->nbr < current_stack_b->nbr
				&& best_match > current_stack_b->nbr)
			{
				best_match = current_stack_b->nbr;
				current_stack_a->target = best_match;
			}
			current_stack_b = current_stack_b->next;
		}
		if (current_stack_a->target == 0)
			current_stack_a->target = find_smallest_element(&stack_b);
		current_stack_a = current_stack_a->next;
	}
}
