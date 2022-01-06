#include "../includes/push_swap.h"

void	ft_del_one(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (*stack != 0)
	{
		printf("test\n");
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
}

void	ft_push_stck(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b == NULL)
		ft_init_lst(stack_b, (*stack_a)->num);
	else
		ft_lstadd_front(stack_b, *stack_a);
	ft_del_one(stack_a);
	return ;
}
