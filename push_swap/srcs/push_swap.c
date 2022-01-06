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

void	push_swap(int ac, char **av)
{
	int		i;
	int		num;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		ft_exit("Too few arguments...\n", 1);
	else if (ac == 2)
		
	num = (int)ft_atoi(av[i]);
	ft_init_lst(&stack_a, num);
	while (++i < ac)
	{
		num = (int)ft_atoi(av[i]);
		ft_lstadd_back(&stack_a, num);
	}
	ft_print_lst(&stack_a, &stack_b);
	printf("\nrotating...\n");
	ft_push_stck(&stack_a, &stack_b);
	ft_push_stck(&stack_a, &stack_b);
	ft_print_lst(&stack_a, &stack_b);
}

int	main(int ac, char **av)
{
	push_swap(ac, av);
	return (0);
}
