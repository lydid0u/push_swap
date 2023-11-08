/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:31:06 by lboudjel          #+#    #+#             */
/*   Updated: 2023/11/07 16:49:25 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//dans cette fonction je choisis si je fais ra rb rra rrb ou rr rr
// par rapport a la position des noeuds dans la stack

void	targeted_and_targeting_at_the_top(t_stack **stack_a, t_stack **stack_b)
{
	t_stack **current_stack_a;
	t_stack **current_stack_b;
	int		targeted;

	current_stack_a = stack_a;
	current_stack_b = stack_b;
	targeted = ;
	
}

// void	big_sort(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	size;
// 	int	position_a;
// 	int	position_b;

// 	size = ft_list_size(*stack_a);
// 	position_a = find_position(*stack_a, (*stack_a)->nbr);
// 	position_b = find_position(*stack_b, (*stack_b)->nbr);
// 	if (position_a <= size / 2 && position_b <= size / 2)
// 	{
// 		if ((*stack_a)->index != 0 && (*stack_b)->index != 0)
// 			rr(stack_a, stack_b);
// 		else if ((*stack_a)->index == 1 && (*stack_b)->index == 0)
// 			rotate_a(stack_a);
// 		else if ((*stack_a)->index == 0 && (*stack_b)->index == 1)
// 			rotate_b(stack_b);
// 	}
// 	else if (position_a >= size / 2 && position_b >= size / 2)
// 	{
// 		if ((*stack_a)->index != 0 && (*stack_b)->index != 0)
// 			rrr(stack_a, stack_b);
// 		else if ((*stack_a)->index == 1 && (*stack_b)->index == 0)
// 			r_rotate_a(stack_a);
// 		else if ((*stack_a)->index == 0 && (*stack_b)->index == 1)
// 			r_rotate_b(stack_b);
// 	}
// 	else
// 	{
// 		if ((*stack_a)->index != 0)
// 		{
// 			if (position_a <= size / 2)
// 				rotate_a(stack_a);
// 			else
// 				r_rotate_a(stack_a);
// 		}
// 		if ((*stack_b)->index != 0)
// 		{
// 			if (position_b <= size / 2)
// 				rotate_b(stack_b);
// 			else
// 				r_rotate_b(stack_b);
// 		}
// 	}
// }

// // les 3 la finalement je les utilise pas mais ca peut etre utile + jai pas fini la rr_or_rrr
// void	rr_or_rrr(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	size;
// 	int	position_a;
// 	int	position_b;

// 	position_a = find_position(*stack_a, (*stack_a)->nbr);
// 	position_b = find_position(*stack_b, (*stack_b)->nbr);
// 	size = ft_list_size(*stack_a);
// 	if (position_a <= size / 2)
// 		rotate_a(stack_a);
// 	else
// 		r_rotate_a(stack_a);
// }

// void	ra_or_rra(t_stack **stack_a)
// {
// 	int	size;
// 	int	position;

// 	position = find_position(*stack_a, (*stack_a)->nbr);
// 	size = ft_list_size(*stack_a);
// 	if (position <= size / 2)
// 		rotate_a(stack_a);
// 	else
// 		r_rotate_a(stack_a);
// }

// void	rb_or_rrb(t_stack **stack_b)
// {
// 	int	size;
// 	int	position;

// 	position = find_position(*stack_b, (*stack_b)->nbr);
// 	size = ft_list_size(*stack_b);
// 	if (position <= size / 2)
// 		rotate_b(stack_b);
// 	else
// 		r_rotate_b(stack_b);
// }

// cette fonction ca sera pour compter les couts mais jai qu'un bout jai a peine commencee
void	cost_finder(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_stack_a;
	t_stack	*current_stack_b;
	int		cheapest;
	int		position_in_b;
	int		i;

	current_stack_a = stack_a;
	while (current_stack_a)
	{
		current_stack_b = stack_b;
		position_in_b = find_position(current_stack_b, current_stack_a->target);
		cheapest = (current_stack_a->index + current_stack_b->index);
		i = 0;
		while (current_stack_a->target != current_stack_b->nbr)
			current_stack_b = current_stack_b->next;
		current_stack_a->cost = (current_stack_a->index + current_stack_b->index);
		ft_printf("cost = %d\n", current_stack_a->cost);
		current_stack_a = current_stack_a->next;
	}
}

int	position_of_the_cheapest_cost(t_stack *stack_a)
{
	t_stack *current_stack_a;
	int cheapest;
	
	current_stack_a = stack_a;
	cheapest = current_stack_a->cost;
	while (current_stack_a)
	{
		if (current_stack_a->cost < cheapest)
			cheapest = find_position(current_stack_a, current_stack_a->nbr);
		current_stack_a = current_stack_a->next;
	}
	return (cheapest);
}