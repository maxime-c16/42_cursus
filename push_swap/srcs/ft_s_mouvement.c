#include "../includes/push_swap.h"

void	ft_swap_stck(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;
	int		swap;

	if (*stack && (*stack)->next)
	{
		temp = *stack;
		swap = temp->num;
		temp2 = (*stack)->next;
		temp->num = temp2->num;
		temp2->num = swap;
	}
	return ;
}

void	ft_swap_cmd(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
	if (cmd[1] == 'a')
	{
		ft_swap_stck(stack_a);
		write(1, "sa\n", 3);
	}
	else if (cmd[1] == 'b')
	{
		ft_swap_stck(stack_b);
		write(1, "sb\n", 3);
	}
	else if (cmd[1] == 's')
	{
		ft_swap_stck(stack_b);
		ft_swap_stck(stack_a);
		write(1, "ss\n", 3);
	}
	return ;
}
