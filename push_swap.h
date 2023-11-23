/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:34:09 by lboudjel          #+#    #+#             */
/*   Updated: 2023/11/23 19:24:49 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	int				cost;
	int				position;
	struct s_stack	*next;
}					t_stack;

void				swap_a(t_stack **stack);
void				swap_b(t_stack **stack);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				push_a(t_stack **stack_a, t_stack **stack_b);
void				push_b(t_stack **stack_a, t_stack **stack_b);
void				rotate_a(t_stack **stack_a);
void				rotate_b(t_stack **stack_a);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				r_rotate_a(t_stack **stack_a);
void				r_rotate_b(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
int					ft_stack_size(t_stack *stack_a);
t_stack				*get_last_node(t_stack *stack);
void				print_stack(t_stack *stack);
int					in_order(t_stack **stack_a);
void				where_am_i(t_stack *stack_a);
long int			ft_atoi(char *str);
int					int_is_correct(const char *str);
int					find_position(t_stack *stack, int nbr);
t_stack				*create_node(t_stack **stack_a, char *argv);
t_stack				*ft_lstnew(int nbr);
int					in_quote(t_stack **stack_a, char *argv);
int					nbr_listed(t_stack **stack_a, int argc, char **argv);
int					check_doubles(t_stack *stack_a);
t_stack				**sort_three(t_stack **stack_a);
t_stack				**sort_four(t_stack **stack_a, t_stack **stack_b);
t_stack				**sort_five(t_stack **stack_a, t_stack **stack_b);
int					find_smol(t_stack **stack);
t_stack				*mv_smol_up(t_stack *stack);
int					targeted(t_stack *stack, int content);
int					cost_definer_a(t_stack *stack_b, int position);
int					cost_definer_b(int sizelist, int position);
int					total_cost(int price_a, int price_b);
void				finding_the_one_to_move(t_stack **stack_a,
						t_stack **stack_b, int *tab, int i);
int					countword(const char *s, char c);
char				*copystr(const char *original, char c);
char				**ft_fill_tab(char const *s, char c, char **tab,
						int len_tab);
char				**ft_split(char const *s, char c);
void				free_node(t_stack *stack_a);
void				free_tab(char **argv);
void				sorting(t_stack **stack_a, t_stack **stack_b);
void				push_to_pile_b(t_stack **stack_a, t_stack **stack_b);
void				move_rr(t_stack **stack_a, t_stack **stack_b, int cheap_a,
						int cheap_b);
void				move_rrr(t_stack **stack_a, t_stack **stack_b, int cheap_a,
						int cheap_b);
void				cest_ciao(t_stack **stack_a, t_stack **stack_b, int cheap_a,
						int cheap_b);
int					find_biggest_element(t_stack **stack);
int					where_is_the_smallest(t_stack *stack);
t_stack				**mv_smol_up_v2(t_stack **stack);

int					each_case(t_stack **stack_a, t_stack **stack_b);
void				print_lst(t_stack *stack_a);

#endif
