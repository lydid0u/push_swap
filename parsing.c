/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:49:22 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/20 18:22:03 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		new_node(t_stack *stack_a, char **argv)
{
	t_stack		*node;
	t_stack		*last;
	long int	nbr;

	nbr = ft_atoi(av1);
	node = ft_lstnew(&nbr);
	if (node == NULL)
		return ;
	if (*stack_a == NULL)
	{
		*stack_a = node;
		return ;
	}
	last = get_last_node(*stack_a);
	last->next = node;
}

t_stack	*ft_lstnew(void *nbr)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}