#include "../includes/push_swap.h"

void	ft_exec_cmd(int	cmd, t_stack **stack_a, t_stack **stack_b)
{
	if (cmd > 0 && cmd < 10)
		ft_push(cmd, stack_a, stack_b);
	else if (cmd > 9 && cmd < 20)
		ft_swap_cmd(cmd, stack_a, stack_b);
	else if (cmd > 19 && cmd < 30)
		ft_rotate(cmd, stack_a, stack_b);
	ft_print_lst(stack_a, stack_b);
	return ;
}
