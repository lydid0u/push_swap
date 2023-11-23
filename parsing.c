/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:49:22 by lboudjel          #+#    #+#             */
/*   Updated: 2023/11/23 19:07:50 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(t_stack **stack_a, char *argv)
{
	t_stack		*node;
	t_stack		*last;
	long int	nbr;

	nbr = ft_atoi(argv);
	if (!(nbr >= -2147483648 && nbr <= 2147483647))
	{
		ft_printf("Error\n");
		free_node(*stack_a);
		exit(0);
	}
	node = ft_lstnew(nbr);
	if (node == NULL)
		return (NULL);
	if (*stack_a == NULL)
	{
		*stack_a = node;
		return (NULL);
	}
	last = get_last_node(*stack_a);
	last->next = node;
	return (node);
}

t_stack	*ft_lstnew(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}

int	in_quote(t_stack **stack_a, char *argv)
{
	char	**arg;
	int		i;

	i = 0;
	arg = ft_split(argv, ' ');
	if (!arg)
		return (free_tab(arg), 0);
	while (arg[i])
	{
		if (int_is_correct(arg[i]) == 0)
			return (free_tab(arg), ft_printf("Error\n"), 0);
		create_node(stack_a, arg[i]);
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
		if (int_is_correct(argv[i]) == 0)
			return (free_node(*stack_a), ft_printf("Error\n"), 0);
		create_node(stack_a, argv[i]);
		if (!stack_a)
			return (free_node(*stack_a), 0);
		i++;
	}
	return (1);
}

int	check_doubles(t_stack *stack_a)
{
	t_stack	*i;
	t_stack	*j;

	i = stack_a;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->nbr == j->nbr)
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}
