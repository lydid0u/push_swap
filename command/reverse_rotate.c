/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:11:41 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/16 16:08:15 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	r_rotate_a(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*temp;

	if (*stack_a && (*stack_a)->next)
	{
		last = get_last_node(*stack_a);
		temp = *stack_a;
        while (temp->next != last)
            temp = temp->next;
        temp->next = NULL;
		last->next = *stack_a;
        *stack_a = last;
		ft_printf("rra\n");
	}
}

void	r_rotate_b(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*temp;

	if (*stack_b && (*stack_b)->next)
	{
		last = get_last_node(*stack_b);
		temp = *stack_b;
        while (temp->next != last)
            temp = temp->next;
        temp->next = NULL;
		last->next = *stack_b;
        *stack_b = last;
		ft_printf("rrb\n");
	}
}

void    rrr(t_stack **stack_a, t_stack **stack_b)
{
   	t_stack	*last;
	t_stack	*temp;
    t_stack	*last_b;
	t_stack	*temp_b;

	if (*stack_a && (*stack_a)->next)
	{
		last = get_last_node(*stack_a);
		temp = *stack_a;
        while (temp->next != last)
            temp = temp->next;
        temp->next = NULL;
		last->next = *stack_a;
        *stack_a = last;
		ft_printf("rra\n");
	}
    if (*stack_b && (*stack_b)->next)
	{
		last_b = get_last_node(*stack_b);
		temp_b = *stack_b;
        while (temp_b->next != last_b)
            temp_b = temp_b->next;
        temp_b->next = NULL;
		last_b->next = *stack_b;
        *stack_b = last_b;
		ft_printf("rrb\n");
	}
}
