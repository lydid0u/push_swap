/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzinabi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:31:06 by lboudjel          #+#    #+#             */
/*   Updated: 2023/11/14 13:32:06 by adzinabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//dans cette fonction je choisis si je fais ra rb rra rrb ou rr rr
// par rapport a la position des noeuds dans la stack

void	targeted_and_targeting_at_the_top(t_stack *stack_a, t_stack *stack_b)
{
	int		position_of_cheapest;
	t_stack	*current_stack_a;
	t_stack	*current_stack_b;

	position_of_cheapest = INT_MAX;
	current_stack_a = stack_a;
	current_stack_b = stack_b;
	while (stack_a)
	{
		position_of_cheapest = position_of_the_cheapest_cost(current_stack_a);
		// printf("position of cheapest first one : %d\n", position_of_cheapest);
		// what_is_the_scenario(current_stack_a, current_stack_b);
		push_the_cheapest_at_the_top(&current_stack_a, &current_stack_b, position_of_cheapest);
		position_of_cheapest = position_of_the_cheapest_cost(current_stack_a);
		printf("position cheapest : %d\n", position_of_cheapest);
		if (position_of_cheapest == 0)
			push_b(&current_stack_a, &current_stack_b);
		printf("stackb\n");
		print_stack(current_stack_b);
		printf("stacka\n");
		print_stack(current_stack_a);
		redefine_everything(&current_stack_a, &current_stack_b);
		if (stack_a == NULL)
			break;
	}
}

void	redefine_everything(t_stack **stack_a, t_stack **stack_b)
{
	index_definer_second_half(*stack_a);
	index_definer_second_half(*stack_b);
	target_finder(*stack_a, *stack_b);
	cost_finder(*stack_a, *stack_b);
}

void	push_the_cheapest_at_the_top(t_stack **stack_a, t_stack **stack_b, int position)
{
	what_is_the_scenario(*stack_a, *stack_b);
	printf("what is the chosen scenario : %d\n", (*stack_a)->scenario);
	// printf("position %d\n", (*stack_a)->position);
//	while ((*stack_a)->position > 0 && position > 0)
//	{
		position = position_of_the_cheapest_cost(*stack_a);
		where_am_i(*stack_a);
		choice_of_scenario(stack_a, stack_b);
	// }
	print_stack(*stack_a);
	print_stack(*stack_b);

}
//ajouter la position ici
void	choice_of_scenario(t_stack **stack_a, t_stack **stack_b)
{
	int	sizelist;
	int sizelist_b;

	sizelist = ft_list_size(*stack_a);
	sizelist_b = ft_list_size(*stack_b);
	ft_vrai_index(*stack_a);
	ft_vrai_index(*stack_b);
	if ((*stack_a)->scenario == 1)
	{
		if ((*stack_a)->vrai_index == sizelist && (*stack_b)->vrai_index != sizelist_b)
			r_rotate_b(stack_b);
		if ((*stack_a)->vrai_index != sizelist && (*stack_b)->vrai_index == sizelist_b)
			r_rotate_a(stack_b);
		else
			rrr(stack_a, stack_b);
	}
	else if ((*stack_a)->scenario == 2)
	{
		if ((*stack_a)->vrai_index == 0 && (*stack_b)->vrai_index != 0)
			rotate_b(stack_b);
		if ((*stack_a)->vrai_index != 0 && (*stack_b)->vrai_index == 0)
			rotate_a(stack_b);
		else
		{
			rotate_a(stack_a);
			rotate_b(stack_b);
		}
	}
	else if ((*stack_a)->scenario == 3)
	{
		if ((*stack_a)->vrai_index == sizelist && (*stack_b)->vrai_index != 0)
			rotate_b(stack_b);
		if ((*stack_a)->vrai_index != sizelist && (*stack_b)->vrai_index == 0)
			r_rotate_a(stack_b);
		else
		{
			r_rotate_a(stack_a);
			rotate_b(stack_b);
		}
	}
	else if ((*stack_a)->scenario == 4)
	{
		if ((*stack_a)->vrai_index == 0 && (*stack_b)->vrai_index != sizelist_b)
			r_rotate_b(stack_b);
		if ((*stack_a)->vrai_index != 0 && (*stack_b)->vrai_index == sizelist_b)
			rotate_a(stack_b);
		else
		{
			rotate_a(stack_a);
			r_rotate_b(stack_b);
		}
	}
}

void	what_is_the_scenario(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_stack_a;
	t_stack	*current_stack_b;
	int	sizelist;
	int sizelist_b;

	sizelist = ft_list_size(stack_a);
	sizelist_b = ft_list_size(stack_b);
	current_stack_a = stack_a;
	current_stack_b = stack_b;
	ft_vrai_index(current_stack_a);
	ft_vrai_index(current_stack_b);
	while (current_stack_a)
	{
		current_stack_b = stack_b;
		while ((current_stack_a)->target != (current_stack_b)->nbr)
		{
    		current_stack_b = (current_stack_b)->next;
		}
    	printf("Debug: %d != %d\n", (current_stack_a)->target, (current_stack_b)->nbr);
		if (((current_stack_a)->vrai_index > sizelist / 2) && ((current_stack_b)->vrai_index > sizelist_b / 2)) // si les deux sont en bas
			(current_stack_a)->scenario = 1;
		else if (((current_stack_a)->vrai_index < sizelist / 2) && ((current_stack_b)->vrai_index < sizelist_b / 2)) // si les deux sont en haut
			(current_stack_a)->scenario = 2;
		else if (((current_stack_a)->vrai_index > sizelist / 2) && ((current_stack_b)->vrai_index < sizelist_b / 2)) // si stack a en bas et stack b en haut
			(current_stack_a)->scenario = 3;
		else if (((current_stack_a)->vrai_index < sizelist / 2) && ((current_stack_b)->vrai_index > sizelist_b / 2)) // si stack b en bas et stack a en haut
			(current_stack_a)->scenario = 4;
		current_stack_a = (current_stack_a)->next;
	}
}

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
		current_stack_a = current_stack_a->next;
	}
}

int	position_of_the_cheapest_cost(t_stack *stack_a)
{
	t_stack		*current_stack_a;
	int			cheapest;

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