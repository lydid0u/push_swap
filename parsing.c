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

t_stack		create_node(t_stack *stack_a, char **argv)
{
	t_stack		*node;
	t_stack		*last;
	long int	nbr;

	nbr = ft_atoi(argv);
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

int	in_quote(t_stack **stack_a, char *arg)
{
	char	**argv;
	int		i;

	i = 0;
	argv = ft_split(arg, ' ');
	if (!arg)
		return (free_tab(argv), 0);
	while (argv[i])
	{
		if (check_int(argv[i]) == 0)
			return (free_tab(argv), ft_printf("Error\n"), 0);
		create_node(stack_a, argv[i]);
		i++;
	}
	if (stack_amount_nodes(*stack_a) == 0)
		return (free_tab(argv), ft_printf("Error\n"), 0);
	return (free_tab(argv), 1);
}

int	nbr_listed(t_stack **stack_a, int argc, char **arg)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_int(arg[i]) == 0)
			return (free_pile(*stack_a), ft_printf("Error\n"), 0);
		create_node(stack_a, arg[i]);
		if (!stack_a)
			return (free_pile(*stack_a), 0);
		i++;
	}
	return (1);
}