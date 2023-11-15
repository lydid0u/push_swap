/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:11:41 by lboudjel          #+#    #+#             */
/*   Updated: 2023/11/15 15:11:31 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	r_rotate_b(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*tmp;

	if (*stack_b && (*stack_b)->next)
	{
		last = get_last_node(*stack_b);
		tmp = *stack_b;
		while (tmp->next != last)
			tmp = tmp->next;
		tmp->next = NULL;
		last->next = *stack_b;
		*stack_b = last;
		ft_printf("rrb\n");
	}
}

void	r_rotate_a(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*tmp;

	if (*stack_a && (*stack_a)->next)
	{
		last = get_last_node(*stack_a);
		tmp = *stack_a;
		while (tmp->next != last)
			tmp = tmp->next;
		tmp->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
		ft_printf("rra\n");
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	r_rotate_a(stack_a);
	r_rotate_b(stack_b);
	ft_printf("rrr\n");
}
