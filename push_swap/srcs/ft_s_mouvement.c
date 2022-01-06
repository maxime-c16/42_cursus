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
