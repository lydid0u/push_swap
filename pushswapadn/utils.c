/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:32:54 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/20 14:46:38 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	correct_int(char *str)
{
	int	i;

	i = 0;
	if ((str[i] >= '0' || str[i] <= '9') || str[i] == '-')
		i++;
	else
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	base;

	i = 0;
	sign = 1;
	base = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9'
		&& base < 2147483647 && base > -2147483648)
	{
		base = base * 10 + (str[i] - '0');
		i++;
	}
	return (base * sign);
}

void	new_node(t_stack **pile_a, char *av1)
{
	t_stack		*new;
	t_stack		*last;
	long int	tmp;

	tmp = ft_atoi(av1);
	new = malloc(sizeof(t_stack));
	if (!new)
		return (free(new));
	new->content = tmp;
	new->next = NULL;
	if (*pile_a == NULL)
	{
		*pile_a = new;
		return ;
	}
	last = get_last_node(*pile_a);
	last->next = new;
}

int	stack_amount_nodes(t_stack *pile_a)
{
	t_stack	*nombre;
	int		i;

	i = 0;
	nombre = pile_a;
	while (nombre->next)
	{
		nombre = nombre->next; 
		i++;
	}
	return (i);
}

t_stack	*get_last_node(t_stack *pile_a)
{
	t_stack	*last;

	last = pile_a;
	while (last->next)
		last = last->next;
	return (last);
}