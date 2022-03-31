/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximecauchy <maximecauchy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:42:03 by maximecauch       #+#    #+#             */
/*   Updated: 2022/03/31 21:42:05 by maximecauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_exec_cmd(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
	if (cmd[0] == 'p')
		ft_push(cmd, stack_a, stack_b);
	else if (cmd[0] == 's')
		ft_swap_cmd(cmd, stack_a, stack_b);
	else if (cmd[0] == 'r')
	{
		if (cmd[2])
			ft_rotate_rr(cmd, stack_a, stack_b);
		else
			ft_rotate(cmd, stack_a, stack_b);
	}
	return ;
}
