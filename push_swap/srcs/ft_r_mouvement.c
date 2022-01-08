#include "../includes/push_swap.h"

void	ft_back_r(t_stack **stack)
{
	int		tmp2;

	tmp2 = (*stack)->num;
	ft_lstadd_back(stack, tmp2);
	ft_del_one(stack);
}

void	ft_rotate_stck(t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	if (*stack && (*stack)->next)
	{
		ft_back_r(&tmp);
		*stack = (*stack)->next;
	}
	return ;
}

void	ft_rotate(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
	if (cmd[1] == 'A')
		ft_rotate_stck(stack_a);
	else if (cmd[1] == 'B')
		ft_rotate_stck(stack_b);
	else if (cmd[1] == 'R')
	{
		ft_rotate_stck(stack_a);
		ft_rotate_stck(stack_b);
	}
	return ;
}
