/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:35:48 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/20 17:46:15 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_list_size(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}

t_stack	*get_last_node(t_stack *stack_a)
{
	t_stack	*last;

	last = stack_a;
	while (last->next)
		last = last->next;
	return (last);
}

int	argv_double(t_stack *stack_a)
{
	t_stack	*i;
	t_stack	*j;
	int		len;
	
	len = ft_list_size(stack_a);
	i = stack_a;
    while (i != NULL)
    {
        j = i->next;
        while (j != NULL)
        {
            if (i->nbr == j->nbr)
            {
                ft_printf("Error\nDuplicate number\n");
                return 0;
            }
            j = j->next;
        }
        i = i->next;
    }
	return (1);
}

int	ft_atoi(char *str)
{
	int i;
	int sign;
	int nb;

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

// int main() {
//
//     t_stack* stack_a = malloc(sizeof(t_stack));
//     stack_a->nbr = 1;

//     stack_a->next = malloc(sizeof(t_stack));
//     stack_a->next->nbr = 2;

//     stack_a->next->next = malloc(sizeof(t_stack));
//     stack_a->next->next->nbr = 3;

//     stack_a->next->next->next = malloc(sizeof(t_stack));
//     stack_a->next->next->next->nbr = 4; 

//     stack_a->next->next->next->next = NULL;

//     if (argv_double(stack_a)) {
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
//     return 0;
// }

