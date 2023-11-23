/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:30:14 by lboudjel          #+#    #+#             */
/*   Updated: 2023/11/23 19:07:39 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_node(t_stack *stack_a)
{
	t_stack	*stack;
	t_stack	*nxt;

	stack = stack_a;
	while (stack != NULL)
	{
		nxt = stack->next;
		free(stack);
		stack = nxt;
	}
}

void	print_lst(t_stack *stack_a)
{
	t_stack	*stack;

	stack = stack_a;
	while (stack != NULL)
	{
		ft_printf("%d", stack->nbr);
		stack = stack->next;
	}
}

void	free_tab(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

// void	ft_tu_vas_avoir_zero(void)
// {
// 	// j'espere tu rate;
// 	// t'es trop nul arrete l'ecole reprends la fac;
// }
