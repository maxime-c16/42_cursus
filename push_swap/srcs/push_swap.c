#include "../includes/push_swap.h"

void	ft_exit(char *exit_msg, int exit_code)
{
	printf("%s", exit_msg);
	exit(exit_code);
	return ;
}

void	ft_print_lst(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack_a;
	tmp2 = *stack_b;
	printf ("\nstack a :\n");
	while (tmp)
	{
		printf("%d -> ", tmp->num);
		tmp = tmp->next;
	}
	printf("(null)\n");
	printf ("\nstack b :\n");
	while (tmp2)
	{
		printf("%d -> ", tmp2->num);
		tmp2 = tmp2->next;
	}
	printf("(null)\n");
	return ;
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
	return ;
}

//make a function that print the index of the stack_a one by one
void	ft_print_index(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	printf ("\nstack a :\n");
	while (tmp)
	{
		printf("%d -> ", tmp->index);
		tmp = tmp->next;
	}
	printf("(null)\n");
	return ;
}

void	push_swap(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*temp;

	stack_a = NULL;
	stack_b = NULL;
	temp = NULL;
	if (ac < 2)
		ft_exit("Too few arguments...\n", 1);
	else if (ac == 2)
		ft_init_index(&stack_a, ft_parse_fill(&stack_a, av[1]));
	radix_sort(&stack_a, &stack_b, temp);
	ft_free_stack(&stack_a);
	//system("leaks push_swap");
	return ;
}

int	main(int ac, char **av)
{
	push_swap(ac, av);
	return (0);
}
