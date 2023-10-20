/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:44:19 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/20 14:23:08 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_tab(char **av1)
{
	int	i;

	i = 0 ;
	while (av1[i])
	{
		free(av1[i]);
		i++;
	}
	free(av1);
}

void	free_pile(t_stack *pile_a)
{
	t_stack	*new;
	t_stack	*stacknow;

	stacknow = pile_a;
	while (stacknow)
	{
		new = stacknow->next;
		free(new);
		stacknow = new;
	}
}

int	doublon(t_stack *pile_a)
{
	t_stack	*first_list;
	t_stack	*second_list;
	int		len;
	int		i;
	
	i = 0;
	len = stack_amount_nodes(pile_a);
	first_list = pile_a;
	second_list = pile_a;
	while (len != 0)
	{
		while (second_list->next)
		{
			if (first_list->content == second_list->next->content)
				i++;
			if (i == 2)
				return (ft_printf("Error\nDoublon"), 0);
			second_list = second_list->next;
		}
		first_list = first_list->next;
		second_list = pile_a;
		i = 0;
		len--;
	}
	return (1);
}