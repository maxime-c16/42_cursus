#include "../includes/push_swap.h"

void	ft_back_r(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = NULL;
	tmp1 = *stack;
	tmp2 = (*stack)->prev;
	while (tmp1->next)
		tmp1 = tmp1->next;
	tmp1->next = tmp2;
	tmp1->next->prev = tmp1;
	tmp1->next->next = NULL;
}

void	ft_rotate_stck(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		*stack = (*stack)->next;
		ft_back_r(stack);
	}
	return ;
}
