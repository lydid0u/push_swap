/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:25:07 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/20 17:45:29 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	(void)argv;
	if (argc < 2)
		return (ft_printf("Error\n"), 0);
	if (argc == 2)
		return 1;
		// split;
	if (argc > 2)
		if (argv_double(stack_a) == 0)
			return(0);
	return (1);	
} 