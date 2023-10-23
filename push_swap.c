/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:25:07 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/20 18:22:38 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	(void)stack_b;
	if (check_doubles(stack_a) == 0)
	if (argc < 2)
		return (ft_printf("Error\n"), 0);
	if (argc == 2)
		in_quote(&stack_a, &argv[1]);
	if (argc < 2)
	{
		nbr_listed(&stack_a, argc, argv);
	}
	return (1);	
} 