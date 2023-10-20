/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrabis2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:13:23 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/20 14:23:08 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_rrbbis(t_stack **pile_b)
{
	t_stack	*tmp;
	t_stack	*other;

	if (*pile_b)
	{
		tmp = *pile_b;
		other = get_last_node(*pile_b);
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = NULL;
		other->next = *pile_b;
		*pile_b = other;
		ft_printf("rrb\n");
	}
}

void	ft_rrabis(t_stack **pile_a)
{
	t_stack	*tmp;
	t_stack	*other;

	if (*pile_a)
	{
		tmp = *pile_a;
		other = get_last_node(*pile_a);
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = NULL;
		other->next = *pile_a;
		*pile_a = other;
		ft_printf("rra\n");
	}
}

void	ft_rrr(t_stack **pile_a, t_stack **pile_b)
{
	ft_rrabis(pile_a);
	ft_rrbbis(pile_b);
	ft_printf("rrr\n");
}

int	check_order(t_stack *pile_a)
{
	t_stack	*tmp;

	tmp = pile_a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}