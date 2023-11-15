void	redefine_everything(t_stack **stack_a, t_stack **stack_b)
{
	where_am_i(*stack_a);
	where_am_i(*stack_b);
	index_definer_second_half(*stack_a);
	index_definer_second_half(*stack_b);
	target_finder(*stack_a, *stack_b);
}

void	printf_lst_target(t_stack *pile_a)
{
	t_stack	*tmp;

	tmp = pile_a;
	printf("liste target : \n");
	while (tmp)
	{
		// ft_printf("%d\n", tmp->target);
		tmp = tmp->next;
	}
	printf("\n\n\n\n");
}

void	choice_of_scenario(t_stack **stack_a, t_stack **stack_b)
{
	int	sizelist;
	int	sizelist_b;

	sizelist = ft_stack_size(*stack_a);
	sizelist_b = ft_stack_size(*stack_b);
	where_am_i(*stack_a);
	where_am_i(*stack_b);
	if ((*stack_a)->scenario == 1)
	{
		if ((*stack_a)->position == sizelist
			&& (*stack_b)->position != sizelist_b)
			r_rotate_b(stack_b);
		if ((*stack_a)->position != sizelist
			&& (*stack_b)->position == sizelist_b)
			r_rotate_a(stack_b);
		else
			rrr(stack_a, stack_b);
	}
	else if ((*stack_a)->scenario == 2)
	{
		if ((*stack_a)->position == 0 && (*stack_b)->position != 0)
			rotate_b(stack_b);
		if ((*stack_a)->position != 0 && (*stack_b)->position == 0)
			rotate_a(stack_b);
		else
		{
			rotate_a(stack_a);
			rotate_b(stack_b);
		}
	}
	else if ((*stack_a)->scenario == 3)
	{
		if ((*stack_a)->position == sizelist && (*stack_b)->position != 0)
			rotate_b(stack_b);
		if ((*stack_a)->position != sizelist && (*stack_b)->position == 0)
			r_rotate_a(stack_b);
		else
		{
			r_rotate_a(stack_a);
			rotate_b(stack_b);
		}
	}
	else if ((*stack_a)->scenario == 4)
	{
		if ((*stack_a)->position == 0 && (*stack_b)->position != sizelist_b)
			r_rotate_b(stack_b);
		if ((*stack_a)->position != 0 && (*stack_b)->position == sizelist_b)
			rotate_a(stack_b);
		else
		{
			rotate_a(stack_a);
			r_rotate_b(stack_b);
		}
	}
}

void	what_is_the_scenario(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_stack_a;
	t_stack	*current_stack_b;
	int		sizelist;
	int		sizelist_b;

	sizelist = ft_stack_size(stack_a);
	sizelist_b = ft_stack_size(stack_b);
	current_stack_a = stack_a;
	current_stack_b = stack_b;
	where_am_i(current_stack_a);
	where_am_i(current_stack_b);
	while (current_stack_a)
	{
		current_stack_b = stack_b;
		while ((current_stack_a)->target != (current_stack_b)->nbr)
		{
			current_stack_b = (current_stack_b)->next;
		}
		printf("WHAT IS SCENARIO : nbr a : %d, nbr b : %d, target : %d\n",
				current_stack_a->nbr,
				current_stack_b->nbr,
				current_stack_a->target);
		if (((current_stack_a)->position > sizelist / 2)
			&& ((current_stack_b)->position > sizelist_b / 2))
			// si les deux sont en bas
			(current_stack_a)->scenario = 1;
		else if (((current_stack_a)->position < sizelist / 2)
				&& ((current_stack_b)->position < sizelist_b / 2))
			// si les deux sont en haut
			(current_stack_a)->scenario = 2;
		else if (((current_stack_a)->position > sizelist / 2)
				&& ((current_stack_b)->position < sizelist_b / 2))
			// si stack a en bas et stack b en haut
			(current_stack_a)->scenario = 3;
		else if (((current_stack_a)->position < sizelist / 2)
				&& ((current_stack_b)->position > sizelist_b / 2))
			// si stack b en bas et stack a en haut
			(current_stack_a)->scenario = 4;
		current_stack_a = (current_stack_a)->next;
	}
}

int	position_of_the_cheapest_cost(t_stack *stack_a)
{
	t_stack	*current_stack_a;
	int		cheapest;

	current_stack_a = stack_a;
	printf(" COST %d\n", current_stack_a->cost);
	cheapest = current_stack_a->cost;
	while (current_stack_a)
	{
		if (current_stack_a->cost < cheapest)
			cheapest = find_position(current_stack_a, current_stack_a->nbr);
		current_stack_a = current_stack_a->next;
	}
	return (cheapest);
}
void	index_definer_second_half(t_stack *stack)
{
	int		sizelist;
	int		i;
	t_stack	*current;

	current = stack;
	sizelist = ft_stack_size(current);
	i = (sizelist / 2);
	index_definer_first_half(current);
	while (current)
	{
		current = current->next;
		if (!current)
			break ;
		if (current->index == i)
		{
			if (sizelist % 2 != 0)
			{
				current = current->next;
				if (!current)
					break ;
				current->index = i;
			}
			break ;
		}
	}
	while (i >= 0 && current)
	{
		current->index = i;
		i--;
		current = current->next;
	}
}

void	index_definer_first_half(t_stack *stack)
{
	int		sizelist;
	int		i;
	int		j;
	t_stack	*current;

	j = 0;
	current = stack;
	sizelist = ft_stack_size(stack);
	i = (sizelist / 2);
	while (i >= 0 && current)
	{
		current->index = j;
		current = current->next;
		j++;
		i--;
	}
}

void	target_finder(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_stack_a;
	t_stack	*current_stack_b;
	int		best_match;

	current_stack_a = stack_a;
	while (current_stack_a)
	{
		current_stack_b = stack_b;
		best_match = INT_MAX;
		while (current_stack_b)
		{
			if (current_stack_a->nbr < current_stack_b->nbr
				&& best_match > current_stack_b->nbr)
			{
				best_match = current_stack_b->nbr;
				current_stack_a->target = best_match;
			}
			current_stack_b = current_stack_b->next;
		} 
		if (current_stack_a->target == 0)
			current_stack_a->target = find_smallest_element(&stack_b);
		current_stack_a = current_stack_a->next;
	}
}

void	where_am_i(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->position = i;
		stack = stack->next;
		i++;
	}
}

void	print_index(t_stack *stack_a)
{
	ft_printf("index\n");
	while (stack_a != NULL)
	{
		ft_printf("%d\n", stack_a->index);
		stack_a = stack_a->next;
	}
	ft_printf("\n");
}
// a faire :
// 1 - compter les prix et les stocker dans une variable
//
// 		en boucle
// 2 - additionner les prix //
// 3 - remonter les noeuds en haut 
// 4 - push 
//
// 		une fois la stack a vide
// 5 - remonter le plus grand tout en haut
// 6 - push en boucle sur a
//
// 7 - finito