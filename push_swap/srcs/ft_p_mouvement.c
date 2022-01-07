#include "../includes/push_swap.h"

void	ft_push(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;

	tmp = NULL;
	if (cmd[1] == 'A')
		ft_push_stck(stack_a, stack_b, tmp);
	else if (cmd[1] == 'B')
		ft_push_stck(stack_b, stack_a, tmp);
	return ;
}

void	ft_del_one(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (*stack)
	{
		printf("test\n");
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	return ;
}

void	ft_push_stck(t_stack **stack_a, t_stack **stack_b, t_stack *tmp)
{
	tmp = NULL;
	if (*stack_b == NULL)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		*stack_b = tmp;
		printf("\ninitialisation stack b\n");
		(*stack_b)->next = NULL;
	}
	else
	{
		tmp = ft_lstnew((*stack_a)->num);
		ft_lstadd_front(stack_b, tmp);
		ft_del_one(stack_a);
	}
	return ;
}
