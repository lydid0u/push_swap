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

t_stack		*create_node(t_stack **stack_a, char **argv)
{
	t_stack		*node;
	t_stack		*last;
	long int	nbr;

	nbr = ft_atoi(*argv);
	node = ft_lstnew(&nbr);
	if (node == NULL)
		return NULL;
	if (*stack_a == NULL)
	{
		*stack_a = node;
		return NULL;
	}
	last = get_last_node(*stack_a);
	last->next = node;
	return (node);
}

t_stack	*ft_lstnew(void *nbr)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->nbr = *(int *)nbr;
	new->next = NULL;
	return (new);
}

int	in_quote(t_stack **stack_a, char **argv)
{
	char	**arg;
	int		i;

	i = 0;
	arg = ft_split(*argv, ' ');
	if (!argv)
		return (free_tab(arg), 0);
	while (arg[i])
	{
		if (correct_int(arg[i], 0) == 0)
			return (free_tab(arg), ft_printf("Error\n"), 0);
		create_node(stack_a, &argv[i]);
		i++;
	}
	return (free_tab(arg), 1);
}

int	nbr_listed(t_stack **stack_a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (correct_int(argv[i], 0) == 0)
			return (free_node(*stack_a), ft_printf("Error\n"), 0);
		create_node(stack_a, &argv[i]);
		if (!stack_a)
			return (free_node(*stack_a), 0);
		i++;
	}
	return (1);
}