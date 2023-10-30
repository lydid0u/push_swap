/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:29:08 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/20 14:27:49 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	one_argument(t_stack **pile_a, char *arg)
{
	char	**av1;
	int		i;

	i = 0;
	av1 = ft_split(arg, ' ');
	if (!arg)
		return (free_tab(av1), 0);
	while (av1[i])
	{
		if (int_is_correct(av1[i]) == 0)
			return (free_tab(av1), ft_printf("Error\n"), 0);
		create_node(pile_a, av1[i]);
		i++;
	}
	if (stack_amount_nodes(*pile_a) == 0)
		return (free_tab(av1), ft_printf("Error\n"), 0);
	return (free_tab(av1), 1);
}

int	multiple_arg(t_stack **pile_a, int argc, char **arg)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (int_is_correct(arg[i]) == 0)
			return (free_pile(*pile_a), ft_printf("Error\n"), 0);
		create_node(pile_a, arg[i]);
		if (!pile_a)
			return (free_pile(*pile_a), 0);
		i++;
	}
	return (1);
}

void	wich_algo(t_stack **pile_a, t_stack **pile_b)
{
	if (stack_amount_nodes(*pile_a) <= 3)
		swap_three_numbers(pile_a);
	else if (stack_amount_nodes(*pile_a) <= 5)
		swap_five_numbers(pile_a, pile_b);
	//else if (stack_amount_nodes(pile_a) > 5)
		//algo plus de 5
}

void	printf_lst(t_stack *pile_a)
{
	t_stack	*tmp;
	
	tmp = pile_a;
	while (tmp)
	{
		ft_printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	printf("\n\n\n\n");
}

int	main(int argc, char **argv)
{
	static t_stack	*pile_a = NULL;
	static t_stack	*pile_b = NULL;

	(void) pile_b;
	if (argc < 2)
		return (ft_printf("Error\n"), 0);
	else if (argc == 2)
	{
		one_argument(&pile_a, argv[1]);
		if (doublon(pile_a) == 0 || stack_amount_nodes(pile_a) == 1)
			return (free_pile(pile_a), 0);
		wich_algo(&pile_a, &pile_b);
	}
	else if (argc > 2)
	{
		if (multiple_arg(&pile_a, argc, argv) == 0)
			return (0);
		if (doublon(pile_a) == 0 || stack_amount_nodes(pile_a) == 1)
			return (free_pile(pile_a), 0);
		wich_algo(&pile_a, &pile_b);
		// ft_printf("\nmain :\n");
		// printf_lst(pile_a);
	}
	return (0);
} 