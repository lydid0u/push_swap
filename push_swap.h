/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:34:09 by lboudjel          #+#    #+#             */
/*   Updated: 2023/10/31 17:59:39 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				target;
	int				cost;
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
int					get_index(t_stack *stack);
t_stack				*get_last_node(t_stack *stack);
int					ft_list_size(t_stack *stack_a);
void				print_stack(t_stack *stack_a);
int					in_order(t_stack **stack_a);

//utils
int					ft_atoi(char *str);
int					int_is_correct(const char *str);
int					find_index(t_stack *stack, int nbr);
int					algorithm(t_stack **stack_a, t_stack **stack_b);

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

//sort_rest
t_stack				**big_sort(t_stack **stack_a, t_stack **stack_b);

//set_up_algo

void				target_finder(t_stack *stack_a, t_stack *stack_b);
void				assigning_target(t_stack *stack_a, t_stack *stack_b);
void				cost_of_movement(t_stack *stack_a, t_stack *stack_b);

//ft_split
int					countword(const char *s, char c);
char				*copystr(const char *original, char c);
char				**ft_fill_tab(char const *s, char c, char **tab,
						int len_tab);
char				**ft_split(char const *s, char c);

//free
void				free_node(t_stack *stack_a);
void				free_tab(char **argv);

#endif