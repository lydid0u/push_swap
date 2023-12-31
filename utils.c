/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:35:48 by lboudjel          #+#    #+#             */
/*   Updated: 2023/11/23 19:15:47 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi(char *str)
{
	long int	i;
	long int	sign;
	long int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb * sign > INT_MAX || nb * sign < INT_MIN)
			return (2147483648);
		i++;
	}
	return (nb * sign);
}

int	int_is_correct(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '-')
			return (0);
		i++;
		if (str[i] == '-')
			return (0);
	}
	return (1);
}

int	find_position(t_stack *stack, int nbr)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = stack;
	if (current == NULL)
		return (0);
	while (current->nbr != nbr)
	{
		i++;
		current = current->next;
	}
	return (i);
}
