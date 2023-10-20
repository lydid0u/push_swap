/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:10:29 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/20 14:23:08 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_five_numbers(t_stack **pile_a, t_stack **pile_b)
{
	min_position_5(pile_a, pile_b);
	min_position_4(pile_a, pile_b);
	swap_three_numbers(pile_a);
	ft_pa(pile_a, pile_b);
	ft_pa(pile_a, pile_b);
}

int	pile_min(t_stack **pile_a)
{
	t_stack	*liste;
	int		i;

	liste = *pile_a;
	i = liste->content;
	while (liste)
	{
		if (i > liste->content)
			i = liste->content;
		liste = liste->next;
	}
	return (i);
}

int	index_min(t_stack **pile_a)
{
	t_stack	*liste;
	int		i;
	int		position;

	i = pile_min(pile_a);
	liste = *pile_a;
	position = 0;
	while (liste)
	{
		if (liste->content == i)
			break ;
		liste = liste->next;
		position++;
	}
	return (position);
}

void	min_position_5(t_stack **pile_a, t_stack **pile_b)
{
	int	min_position;

	min_position = index_min(pile_a);
	if (min_position == 0)
		return (ft_pb(pile_a, pile_b));
	else if (min_position == 1)
		return (ft_sa(pile_a), ft_pb(pile_a, pile_b));
	else if (min_position == 2)
		return (ft_ra(pile_a), ft_ra(pile_a), ft_pb(pile_a, pile_b));
	else if (min_position == 3)
		return (ft_rra(pile_a), ft_rra(pile_a), ft_pb(pile_a, pile_b));
	else if (min_position == 4)
		return (ft_rra(pile_a), ft_pb(pile_a, pile_b));
}

void	min_position_4(t_stack **pile_a, t_stack **pile_b)
{
	int	min_position;

	min_position = index_min(pile_a);
	if (min_position == 0)
		return (ft_pb(pile_a, pile_b));
	if (min_position == 1)
		return (ft_rra(pile_a), ft_pb(pile_a, pile_b));
	if (min_position == 2)
		return (ft_rra(pile_a), ft_rra(pile_a), ft_pb(pile_a, pile_b));
	if (min_position == 3)
		return (ft_rra(pile_a), ft_pb(pile_a, pile_b));
}
