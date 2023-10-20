/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrabis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:40:09 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/20 14:23:08 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_rabis(t_stack **pile_a)
{
	t_stack	*tmp;
	t_stack	*last_node;

	tmp = *pile_a;
	last_node = get_last_node(*pile_a);
	last_node->next = tmp;
	*pile_a = tmp->next;
	tmp->next = NULL;
}

void	ft_rbbis(t_stack **pile_b)
{
	t_stack	*tmp;
	t_stack	*last_node;

	tmp = *pile_b;
	last_node = get_last_node(*pile_b);
	last_node->next = tmp;
	*pile_b = tmp->next;
	tmp->next = NULL;
}

void	ft_rr(t_stack **pile_a, t_stack **pile_b)
{
	ft_rabis(pile_a);
	ft_rbbis(pile_b);
	ft_printf("rr\n");
}

void	ft_rrb(t_stack **pile_b)
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
