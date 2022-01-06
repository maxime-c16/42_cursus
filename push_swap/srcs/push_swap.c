#include "../includes/push_swap.h"

void	ft_exit(char *exit_msg, int exit_code)
{
	printf("%s", exit_msg);
	exit(exit_code);
	return ;
}

void	ft_print_lst(t_stack **stack)
{
	while ((*stack)->next)
	{
		printf("%d -> ", (*stack)->num);
		*stack = (*stack)->next;
	}
	printf("(null)\n");
}

int	main(int ac, char **av)
{
	int	i;
	int num;
	t_stack	*stack_a;
	t_stack	*tmp;
	//t_stack	*stack_b;


	i = 1;
	stack_a = NULL;
	if (ac < 2)
		ft_exit("Too few arguments...\n", 1);
	num = (int)ft_atoi(av[i]);
	ft_init_lst(&stack_a, num);
	while (++i < ac)
	{
		num = (int)ft_atoi(av[i]);
		printf("num = %d\n", num);
		ft_lstadd_back(&stack_a, num);
	}
	tmp = stack_a;
	ft_print_lst(&stack_a);
	printf("rotating...\n");
	ft_rotate_stck(&stack_a);
	ft_print_lst(&stack_a);

	return (0);
}
