/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzinabi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:16:44 by lboudjel          #+#    #+#             */
/*   Updated: 2023/11/13 16:28:08 by adzinabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*tmp;

	if (*stack_a && (*stack_a)->next)
	{
		tmp = *stack_a;
		last = get_last_node(*stack_a);
		last->next = tmp;
		*stack_a = tmp->next;
		tmp->next = NULL;
		ft_printf("ra\n");
	}
}

void	rotate_b(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*tmp;

	if (*stack_b && (*stack_b)->next)
	{
		tmp = *stack_b;
		last = get_last_node(*stack_b);
		last->next = tmp;
		*stack_b = tmp->next;
		tmp->next = NULL;
		ft_printf("rb\n");
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*last_a;
	t_stack	*temp_a;
	t_stack	*last_b;
	t_stack	*temp_b;

	if (*stack_a && (*stack_a)->next)
	{
		temp_a = *stack_a;
		last_a = get_last_node(*stack_a);
		last_a->next = temp_a;
		*stack_a = temp_a->next;
		temp_a->next = NULL;
	}
	if (*stack_b && (*stack_b)->next)
	{
		temp_b = *stack_b;
		last_b = get_last_node(*stack_b);
		last_b->next = temp_b;
		*stack_b = temp_b->next;
		temp_b->next = NULL;
	}
	ft_printf("rr\n");
}
