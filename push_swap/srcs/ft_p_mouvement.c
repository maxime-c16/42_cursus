#include "../includes/push_swap.h"

void	ft_push(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = NULL;
	if (cmd[1] == 'a')
	{
		ft_push_stck(stack_b, stack_a, tmp);
		write(1, "pa\n", 3);
	}
	else if (cmd[1] == 'b')
	{
		ft_push_stck(stack_a, stack_b, tmp);
		write(1, "pb\n", 3);
	}
	return ;
}

void	ft_del_one(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else if (*stack && !(*stack)->next)
		*stack = NULL;
	return ;
}

void	ft_push_stck(t_stack **stack_a, t_stack **stack_b, t_stack *tmp)
{
	int	index;

	tmp = NULL;
	index = (*stack_a)->index;
	if (!*stack_b && *stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		*stack_b = tmp;
		(*stack_b)->next = NULL;
	}
	else if (*stack_b && *stack_a)
	{
		tmp = ft_lstnew((*stack_a)->num, index);
		ft_lstadd_front(stack_b, tmp);
		ft_del_one(stack_a);
	}
	return ;
}
