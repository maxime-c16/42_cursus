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
	if (cmd[1] == 'A')
	{
		ft_swap_stck(stack_a);
		ft_putstr_fd("SA\n", 1);
	}
	else if (cmd[1] == 'B')
	{
		ft_swap_stck(stack_b);
		ft_putstr_fd("SB\n", 1);
	}
	else if (cmd[1] == 'S')
	{
		ft_swap_stck(stack_b);
		ft_swap_stck(stack_a);
		ft_putstr_fd("SS\n", 1);
	}
	return ;
}
