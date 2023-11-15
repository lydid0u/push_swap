/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:50:05 by lboudjel          #+#    #+#             */
/*   Updated: 2023/11/15 17:42:48 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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