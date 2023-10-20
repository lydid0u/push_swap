/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:29:32 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/20 14:23:08 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

int		ft_is_charset(char c, char charset);
int		ft_is_word(char *str, char charset);
char	**ft_malloc_word(char *str, char charset, char **dest, int word);
char	**ft_put_word(char *str, char charset, char **dest);
char	**ft_split(const char *str, char charset);
int		main(int argc, char **argv);
int		one_argument(t_stack **pile_a, char *arg);
void	new_node(t_stack **pile_a, char *av1);
int		ft_atoi(const char *str);
t_stack	*get_last_node(t_stack *pile_a);
int		stack_amount_nodes(t_stack *pile_a);
void	free_tab(char **av1);
int		check_int(char *str);
void	free_pile(t_stack *pile_a);
int		doublon(t_stack *pile_a);

void	swap_three_numbers(t_stack **pile_a);
void	swap_five_numbers(t_stack **pile_a, t_stack **pile_b);
int		pile_min(t_stack **pile_a);
int		index_min(t_stack **pile_a);
void	min_position_5(t_stack **pile_a, t_stack **pile_b);
void	min_position_4(t_stack **pile_a, t_stack **pile_b);

//mouvement

void	ft_ss(t_stack **pile_a, t_stack **pile_b);
void	ft_sbbis(t_stack **pile_b);
void	ft_sabis(t_stack **pile_a);
void	ft_sb(t_stack **pile_b);
void	ft_sa(t_stack **pile_a);
void	ft_pa(t_stack **pile_a, t_stack **pile_b);
void	ft_pb(t_stack **pile_a, t_stack **pile_b);
void	ft_ra(t_stack **pile_a);
void	ft_rb(t_stack **pile_b);
void	ft_rrb(t_stack **pile_b);
void	ft_rra(t_stack **pile_a);
void	ft_rrr(t_stack **pile_a, t_stack **pile_b);
void	ft_rrbbis(t_stack **pile_b);
void	ft_rrabis(t_stack **pile_a);

void	wich_algo(t_stack **pile_a, t_stack **pile_b);
int		check_order(t_stack *pile_a);

void	printf_lst(t_stack *pile_a);
void	nombre_de_coup(t_stack **pile_a, t_stack **pile_b);

#endif