#include "../includes/push_swap.h"

void	ft_exec_cmd(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
	if (cmd[0] == 'P')
		ft_push(cmd, stack_a, stack_b);
	else if (cmd[0] == 'S')
		ft_swap_cmd(cmd, stack_a, stack_b);
	else if (cmd[0] == 'R')
	{
		if (cmd[2])
			ft_rotate_rr(cmd, stack_a, stack_b);
		else
			ft_rotate(cmd, stack_a, stack_b);
	}
	ft_print_lst(stack_a, stack_b);
	return ;
}
