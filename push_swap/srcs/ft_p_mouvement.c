#include "../includes/push_swap.h"

void	ft_push(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;

	tmp = NULL;
	if (cmd[1] == 'A')
	{
		ft_push_stck(stack_a, stack_b, tmp);
		ft_putstr_fd("PA\n", 1);
	}
	else if (cmd[1] == 'B')
	{
		ft_push_stck(stack_b, stack_a, tmp);
		ft_putstr_fd("PB\n", 1);
	}
	return ;
}

void	ft_del_one(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
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
	tmp = NULL;
	if (!*stack_b && *stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		*stack_b = tmp;
		(*stack_b)->next = NULL;
	}
	else if (*stack_b && *stack_a)
	{
		tmp = ft_lstnew((*stack_a)->num);
		ft_lstadd_front(stack_b, tmp);
		ft_del_one(stack_a);
	}
	return ;
}
