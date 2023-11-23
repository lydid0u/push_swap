/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:31:06 by lboudjel          #+#    #+#             */
/*   Updated: 2023/11/23 16:48:38 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stack **stack_a, t_stack **stack_b)
{
	int	sizelist;
	int	cheapest[2];

	sizelist = ft_stack_size(*stack_b);
	while (sizelist > 0)
	{
		finding_the_one_to_move(stack_a, stack_b, cheapest, 0);
		cest_ciao(stack_a, stack_b, cheapest[0], cheapest[1]);
		sizelist--;
	}
}

void	push_to_pile_b(t_stack **stack_a, t_stack **stack_b)
{
	int		size;

	size = ft_stack_size(*stack_a);
	while (size > 3)
	{
		push_b(stack_a, stack_b);
		size--;
	}
}

void	move_rr(t_stack **stack_a, t_stack **stack_b, int cheap_a, int cheap_b)
{
	while (cheap_b < 0)
	{
		if (cheap_a < 0)
		{
			rr(stack_a, stack_b);
			cheap_a++;
		}
		else
			rotate_a(stack_a);
		cheap_b++;
	}
	while (cheap_a < 0)
	{
		rotate_b(stack_b);
		cheap_a++;
	}
}

void	move_rrr(t_stack **stack_a, t_stack **stack_b, int cheap_a, int cheap_b)
{
	while (cheap_b > 0)
	{
		if (cheap_a > 0)
		{
			rrr(stack_a, stack_b);
			cheap_a--;
		}
		else
			r_rotate_a(stack_a);
		cheap_b--;
	}
	while (cheap_a > 0)
	{
		r_rotate_b(stack_b);
		cheap_a--;
	}
}

void	cest_ciao(t_stack **stack_a, t_stack **stack_b, int cheap_a,
		int cheap_b)
{
	move_rrr(stack_a, stack_b, cheap_a, cheap_b);
	move_rr(stack_a, stack_b, cheap_a, cheap_b);
	push_a(stack_a, stack_b);
}
