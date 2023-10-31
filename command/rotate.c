/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:16:44 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/31 16:32:12 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*temp;

	if (*stack_a && (*stack_a)->next)
	{
		temp = *stack_a;
		last = get_last_node(*stack_a);
		last->next = temp;
		*stack_a = temp->next;
		temp->next = NULL;
		ft_printf("ra\n");
	}
}

void	rotate_b(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*temp;

	if (*stack_b && (*stack_b)->next)
	{
		temp = *stack_b;
		last = get_last_node(*stack_b);
		last->next = temp;
		*stack_b = temp->next;
		temp->next = NULL;
		ft_printf("ra\n");
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
