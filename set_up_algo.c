/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:50:05 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/31 18:00:52 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_finder(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a)
	{
		assigning_target(stack_a, stack_b);
		stack_a = stack_a->next;
	}
}

void	assigning_target(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b)
	{
		if (stack_a->nbr > stack_b->nbr && stack_a->nbr < stack_b->next->nbr)
			stack_a->target = stack_b->next->nbr;
		stack_b = stack_b->next;
	}
}

void	cost_of_movement(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
}
