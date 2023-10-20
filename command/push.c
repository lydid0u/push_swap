/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:10:26 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/20 14:36:48 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// pa(push a)
// 	: Prend le premier élément au sommet de b et le met sur a.
// Ne fait rien si b est vide.

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_a;
	int		tmp;

	first_a = malloc(sizeof(t_stack));
	if (first_a == NULL)
		return ;
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = (*stack_b)->nbr;
	first_a->nbr = tmp;
	first_a->next = *stack_a;
	*stack_a = first_a;
	*stack_b = (*stack_b)->next;
	write(1, "pa\n", 3);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	if (*stack_a)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = *stack_b;
		*stack_b = temp;
		ft_printf("pb\n");
	}
}