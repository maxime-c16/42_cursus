#include "../includes/push_swap.h"

void	ft_rotate_rr_stck(t_stack **stack)
{
	t_stack	*tmp;

	tmp = ft_lstlast(stack);
	tmp->prev->next = NULL;
	printf("rev B\n");
	ft_lstadd_front(stack, tmp);
}

void	ft_rotate_rr(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
	if (cmd[2] == 'A')
		ft_rotate_rr_stck(stack_a);
	else if (cmd[2] == 'B')
		ft_rotate_rr_stck(stack_b);
	else if (cmd[2] == 'R')
	{
		ft_rotate_rr_stck(stack_a);
		ft_rotate_rr_stck(stack_b);
	}
	return ;
}
