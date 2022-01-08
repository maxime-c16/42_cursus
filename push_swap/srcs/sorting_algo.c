#include "../includes/push_swap.h"

int	get_max(t_stack **stack)
{
	int		temp;
	t_stack	*temp2;

	temp2 = *stack;
	temp = temp2->num;
	while (*stack && (*stack)->next)
	{
		if (temp2->num > temp)
			temp = temp2->num;
		temp2 = temp2->next;
	}
	return (temp);
}
