/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:34:09 by lboudjel          #+#    #+#             */
/*   Updated: 2023/11/21 12:37:07 by lboudjel         ###   ########.fr       */
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

//					command					//
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

//utils_lists
t_stack				*get_last_node(t_stack *stack);
int					ft_stack_size(t_stack *stack_a);
void				print_stack(t_stack *stack);
int					in_order(t_stack **stack_a);

//utils
int					ft_atoi(char *str);
int					int_is_correct(const char *str);
int					find_position(t_stack *stack, int nbr);
int					algorithm(t_stack **stack_a, t_stack **stack_b);

void				print_index(t_stack *stack_a);

//parsing
t_stack				*create_node(t_stack **stack_a, char *argv);
t_stack				*ft_lstnew(void *nbr);
int					in_quote(t_stack **stack_a, char *argv);
int					nbr_listed(t_stack **stack_a, int argc, char **argv);
int					check_doubles(t_stack *stack_a);

//sort 3 and 5
t_stack				**sort_three(t_stack **stack_a);
t_stack				**sort_five(t_stack **stack_a, t_stack **stack_b);
t_stack				**sort_four(t_stack **stack_a, t_stack **stack_b);
int					find_smol(t_stack **stack);
t_stack				*mv_smol_up(t_stack *stack);

//set_up_algo
void				index_definer_first_half(t_stack *stack);
void				index_definer_second_half(t_stack *stack);
int					find_biggest_element(t_stack **stack);
void				target_finder(t_stack *stack_a, t_stack *stack_b);
void				where_am_i(t_stack *stack_a);

//ft_split
int					countword(const char *s, char c);
char				*copystr(const char *original, char c);
char				**ft_fill_tab(char const *s, char c, char **tab,
						int len_tab);
char				**ft_split(char const *s, char c);

//free
void				free_node(t_stack *stack_a);
void				free_tab(char **argv);

//sort_rest
void				printf_lst_target(t_stack *stack_a);
int					position_of_the_cheapest_cost(t_stack *stack_a);
void				choice_of_scenario(t_stack **stack_a, t_stack **stack_b);
void				what_is_the_scenario(t_stack *stack_a, t_stack *stack_b);
void				redefine_everything(t_stack **stack_a, t_stack **stack_b);
int cost_definer_a(t_stack *stack_b, int position);
int cost_definer_b(int sizelist, int position);
int					total_cost(int price_a, int price_b);
void				finding_the_one_to_move(t_stack **stack_a,
						t_stack **stack_b, int *tab);
void				allez_ca_part(t_stack **stack_a, t_stack **stack_b,
						int cheap_a, int cheap_b);
void				sorting(t_stack **stack_a, t_stack **stack_b);
void				push_to_pile_b(t_stack **stack_a, t_stack **stack_b);
void				put_min_top(t_stack **stack);
int	get_min_content(t_stack *stack);
int	get_max_content(t_stack *stack);
int	get_min_pos(t_stack *stack);


#endif
