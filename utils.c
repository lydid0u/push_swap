/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:35:48 by lboudjel          #+#    #+#             */
/*   Updated: 2023/11/06 14:35:36 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
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
	int	i;

	i = 0;
	if (stack == NULL)
		return (0);
	while (stack->nbr != nbr)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

// int main() {

//     t_stack* stack_a = malloc(sizeof(t_stack));
//     stack_a->nbr = 1;

//     stack_a->next = malloc(sizeof(t_stack));
//     stack_a->next->nbr = 2;

//     stack_a->next->next = malloc(sizeof(t_stack));
//     stack_a->next->next->nbr = 3;

//     stack_a->next->next->next = malloc(sizeof(t_stack));
//     stack_a->next->next->next->nbr = 4;

//     stack_a->next->next->next->next = NULL;

//     if (check_doubles(stack_a)) {
//         printf("Aucun doublon trouvé dans la liste chaînée.\n");
//     } else {
//         printf("Des doublons ont été trouvés dans la liste chaînée.\n");
//     }

//     t_stack* current = stack_a;
//     while (current != NULL) {
//         t_stack* temp = current;
//         current = current->next;
//         free(temp);
//     }
//     return (0);
// }