/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:27:05 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/20 14:23:08 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_three_numbers(t_stack **pile_a)
{
	if ((*pile_a)->content > (*pile_a)->next->content
		&& (*pile_a)->next->content < (*pile_a)->next->next->content
		&& (*pile_a)->content < (*pile_a)->next->next->content)
		ft_sa(pile_a);
	else if ((*pile_a)->content > (*pile_a)->next->content
		&& (*pile_a)->next->content > (*pile_a)->next->next->content
		&& (*pile_a)->content > (*pile_a)->next->next->content)
	{
		ft_sa(pile_a);
		ft_rra(pile_a);
	}
	else if ((*pile_a)->content > (*pile_a)->next->content
		&& (*pile_a)->next->content < (*pile_a)->next->content
		< (*pile_a)->next->next->content && (*pile_a)->content
		> (*pile_a)->next->next->content)
		ft_ra(pile_a);
	else if ((*pile_a)->content < (*pile_a)->next->content
		&& (*pile_a)->next->content > (*pile_a)->next->next->content
		&& (*pile_a)->content < (*pile_a)->next->next->content)
	{
		ft_sa(pile_a);
		ft_ra(pile_a);
	}
	else if ((*pile_a)->content < (*pile_a)->next->content
		&& (*pile_a)->next->content > (*pile_a)->next->next->content
		&& (*pile_a)->content > (*pile_a)->next->next->content)
		ft_rra(pile_a);
}
