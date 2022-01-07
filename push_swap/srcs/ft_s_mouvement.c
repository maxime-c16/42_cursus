#include "../includes/push_swap.h"

void	ft_swap_stck(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;
	int		swap;

	temp = *stack;
	swap = temp->num;
	if (!*stack || !(*stack)->next)
		return ;
	temp2 = (*stack)->next;
	temp->num = temp2->num;
	temp2->num = swap;
	return ;
}

void	ft_swap_cmd(int cmd, t_stack **stack_a, t_stack **stack_b)
{
	if (cmd == 10)
		ft_swap_stck(stack_a);
	else if (cmd == 11)
		ft_swap_stck(stack_b);
	else if (cmd == 12)
	{
		ft_swap_stck(stack_b);
		ft_swap_stck(stack_a);
	}
	return ;
}
