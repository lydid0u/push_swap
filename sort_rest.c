/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:31:06 by lboudjel          #+#    #+#             */
/*   Updated: 2023/11/15 18:36:44 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_content(t_stack *pile)
{
	t_stack	*current;
	int		min;

	current = pile;
	min = 2147483647;
	while (current)
	{
		if (current->nbr < min)
			min = current->nbr;
		current = current->next;
	}
	return (min);
}

int	get_max_content(t_stack *pile)
{
	t_stack	*current;
	int		max;

	current = pile;
	max = 0;
	while (current)
	{
		if (current->nbr > max)
			max = current->nbr;
		current = current->next;
	}
	return (max);
}

int	get_min_pos(t_stack *stack)
{
	t_stack	*current;
	t_stack	*min_node;
	int		i;
	int		j;

	current = stack;
	min_node = stack;
	i = 0;
	j = 0;
	while (current)
	{
		if (min_node->nbr > current->nbr)
		{
			j = i;
			min_node = current;
		}
		current = current->next;
		i++;
	}
	return (j);
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

void	sorting(t_stack **stack_a, t_stack **stack_b)
{
	int		sizelist;
	int		cheapest[2];

	sizelist = ft_stack_size(*stack_b);
	while (sizelist > 0)
	{
		finding_the_one_to_move(stack_a, stack_b, cheapest);
		allez_ca_part(stack_a, stack_b, cheapest[0], cheapest[1]);
		sizelist--;
	}
}

void	push_to_pile_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *current;
	int		size;

	current = *stack_a;
	size = ft_stack_size(*stack_a);
	while(size > 3)
	{
		push_b(stack_a, stack_b);
		size--;
	}
	sort_three(stack_a);
}

void	put_min_top(t_stack **stack)
{
	if (get_min_pos(*stack) <= ft_stack_size(*stack) / 2)
	{
		while (get_min_pos(*stack) != 0)
			rotate_a(stack);
	}
	else
	{
		while (get_min_pos(*stack) != 0)
			r_rotate_a(stack);
	}
}

void	help2(t_stack **stack_a, t_stack **stack_b, int cheap_a)
{
	if (cheap_a > 0)
	{
		rrr(stack_a, stack_b);
		ft_printf("rrr\n");
	}
	else
		r_rotate_a(stack_a);
}

void	help3(t_stack **stack_a, t_stack **stack_b, int cheap_a)
{
	if (cheap_a < 0)
		rr(stack_a, stack_b);
	else
		rotate_a(stack_a);
}

void	allez_ca_part(t_stack **stack_a, t_stack **stack_b, int cheap_a, int cheap_b)
{
	while (cheap_b > 0)
	{
		help2(stack_a, stack_b, cheap_a);
		if (cheap_a > 0)
			cheap_a--;
		cheap_b--;
	}
	while (cheap_a > 0)
	{
		r_rotate_b(stack_b);
		cheap_a--;
	}
	while (cheap_b < 0)
	{
		help3(stack_a, stack_b, cheap_a);
		if (cheap_a < 0)
			cheap_a++;
		cheap_b++;
	}
	while (cheap_a < 0)
	{
		rotate_b(stack_b);
		cheap_a++;
	}
	push_a(stack_a, stack_b);
}

void	finding_the_one_to_move(t_stack **stack_a, t_stack **stack_b, int *tab)
{
	t_stack		*current_stack;
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
		price_b = cost_definer(taille_b, second_price(*stack_a, current_stack->nbr));
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
