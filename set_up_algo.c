/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:50:05 by lboudjel          #+#    #+#             */
/*   Updated: 2023/11/21 12:34:10 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finding_the_one_to_move(t_stack **stack_a, t_stack **stack_b, int *tab)
{
	t_stack	*current_stack;
	int		cost;
	int		max;
	int		price_a;
	int		price_b;
	int		i;
	int		taille_a;
	int		taille_b;

	i = 0;
	max = 2147483647;
	current_stack = *stack_b;
	taille_a = ft_stack_size(*stack_b);
	taille_b = ft_stack_size(*stack_a);
	while (current_stack)
	{
		price_a = cost_definer(taille_a, i);
		price_b = cost_definer(taille_b, second_price(*stack_a,
					current_stack->nbr));
		cost = total_cost(price_a, price_b);
		if (max > cost)
		{
			max = cost;
			tab[0] = price_a;
			tab[1] = price_b;
		}
		i++;
		current_stack = current_stack->next;
	}
}

int	second_price(t_stack *stack, int content)
{
	t_stack	*current;
	t_stack	*prev;
	int		i;
	int		index;

	current = stack;
	prev = get_last_node(stack);
	i = 0;
	index = 0;
	if (content > get_max_content(stack) || content < get_min_content(stack))
		return (get_min_pos(stack));
	while (current)
	{
		if (content < current->nbr && content > prev->nbr)
			index = i;
		i++;
		prev = current;
		current = current->next;
	}
	return (index);
}

int	total_cost(int price_a, int price_b)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (price_a < 0)
		a = price_a * -1;
	else if (price_a > 0)
		a = price_a;
	if (price_b < 0)
		b = price_b * -1;
	else if (price_b > 0)
		b = price_b;
	if ((price_a < 0 && price_b < 0) || (price_a > 0 && price_b > 0))
	{
		if (a >= b)
			return (a);
		return (b);
	}
	return (a + b);
}

int	cost_definer(int sizelist_a, int position)
{
	int	cost;

	cost = 0;
	if (position > sizelist_a / 2)
		cost = sizelist_a - position;
	else
		cost = -position;
	return (cost);
}
