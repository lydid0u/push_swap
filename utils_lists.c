/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:31:09 by lboudjel          #+#    #+#             */
/*   Updated: 2023/11/23 15:46:25 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}

t_stack	*get_last_node(t_stack *stack_a)
{
	t_stack	*last;

	last = stack_a;
	while (last->next)
		last = last->next;
	return (last);
}

void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		ft_printf("%d ", stack->nbr);
		stack = stack->next;
	}
	ft_printf("\n\n");
}

int	in_order(t_stack **stack_a)
{
	t_stack	*i;
	t_stack	*j;

	if (stack_a == NULL)
		return (0);
	i = *stack_a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->nbr > j->nbr)
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}

void	where_am_i(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->position = i;
		stack = stack->next;
		i++;
	}
}
