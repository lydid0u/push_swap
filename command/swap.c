#include "../push_swap.h"

// en gros on utilise un double ptr pour modifier la pile et pas juste les donnes de la pile,
// un seul ptr va modifier la copie de la pile
// alors que double pointeur va modifier l'adresse memoire de la pile elle meme

void	swap_a(t_stack **stack_a)
{
	int	temp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temp = (*stack_a)->nbr;
	(*stack_a)->nbr = (*stack_a)->next->nbr;
	(*stack_a)->next->nbr = temp;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **stack_b)
{
	int	temp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp = (*stack_b)->nbr;
	(*stack_b)->nbr = (*stack_b)->next->nbr;
	(*stack_b)->next->nbr = temp;
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	int	temp_a;
	int	temp_b;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp_a = (*stack_a)->nbr;
	(*stack_a)->nbr = (*stack_a)->next->nbr;
	(*stack_a)->next->nbr = temp_a;
	temp_b = (*stack_b)->nbr;
	(*stack_b)->nbr = (*stack_b)->next->nbr;
	(*stack_b)->next->nbr = temp_b;
	write(1, "ss\n", 3);
}

// pa(push a)
// 	: Prend le premier élément au sommet de b et le met sur a.Ne fait rien si b est vide.

// void push_a(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack *first_a;
// 	t_stack *tmp;
	
// 	first_a = malloc(sizeof(t_stack));
// 	tmp = malloc(sizeof(t_stack));
// 	if (first_a == NULL)
// 		return ;
// 	if (*stack_a == NULL || (*stack_a)->next == NULL)
// 		return ;
// 	if (*stack_b == NULL || (*stack_b)->next == NULL)
// 		return ;


// 	tmp = (*stack_b)->nbr;
// 	first_a->nbr = tmp;
	
// 	first_a->next = *stack_a;
// 	*stack_a = first_a;
// 	tmp = *stack_b;
// 	*stack_b = (*stack_b)->next;
// 	write(1, "pa\n", 3);


// }

int	main(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*elem1;
	t_stack	*elem2;
	t_stack	*elem3;
	t_stack	*elem4;
	t_stack	*elem_b1;
	t_stack	*elem_b2;

	// Création de deux piles vides
	stack_a = NULL;
	stack_b = NULL;
	// Ajout de quelques éléments dans les piles pour le test
	elem1 = malloc(sizeof(t_stack));
	elem2 = malloc(sizeof(t_stack));
	elem3 = malloc(sizeof(t_stack));
	elem4 = malloc(sizeof(t_stack));
	elem_b1 = malloc(sizeof(t_stack));
	elem_b2 = malloc(sizeof(t_stack));
	elem1->nbr = 4;
	elem2->nbr = 2;
	elem3->nbr = 3;
	elem4->nbr = 1;
	// Empiler les éléments dans stack_a
	elem1->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	elem4->next = NULL;
	stack_a = elem1;
	if (elem_b1 == NULL)
	{
		fprintf(stderr, "Erreur d'allocation mémoire.\n");
		return (1);
	}
	elem_b1->nbr = 1;
	elem_b2->nbr = 2;
	elem_b1->next = elem_b2;
	elem_b2->next = NULL;
	stack_b = elem_b1; // stack_b pointe maintenant vers l'élément vide
	// Affichage des piles avant l'appel à la fonction ss
	printf("Avant ss:\n");
	printf("Stack A: %d -> %d -> %d\n", stack_a->nbr, stack_a->next->nbr,
			stack_a->next->next->nbr);
	printf("Stack B: %d -> %d\n", stack_b->nbr, stack_b->next->nbr);
	// Appel à la fonction ss
	if (stack_a != NULL && stack_b != NULL)
	{
		ss(&stack_a, &stack_b);
	}
	else
	{
		// Gérer le cas où stack_a ou stack_b est NULL
		fprintf(stderr, "Erreur : stack_a ou stack_b est NULL.\n");
		// Autres actions à prendre en cas d'erreur, comme quitter le programme
	}
	// Affichage des piles après l'appel à la fonction ss
	printf("\nAprès ss:\n");
	printf("Stack A: %d -> %d -> %d\n", stack_a->nbr, stack_a->next->nbr,
			stack_a->next->next->nbr);
	printf("Stack B: %d -> %d\n", stack_b->nbr, stack_b->next->nbr);
	// Libération de la mémoire
	free(elem1);
	free(elem2);
	free(elem3);
	free(elem4);
	free(elem_b1);
	free(elem_b2);
	return (0);
}
