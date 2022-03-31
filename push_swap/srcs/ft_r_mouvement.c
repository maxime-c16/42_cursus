/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_mouvement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximecauchy <maximecauchy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:43:27 by maximecauch       #+#    #+#             */
/*   Updated: 2022/03/31 21:43:28 by maximecauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_back_r(t_stack **stack)
{
	int		tmp2;
	int		index;

	index = (*stack)->index;
	tmp2 = (*stack)->num;
	ft_lstadd_back(stack, tmp2, index);
	ft_del_one(stack);
}

void	ft_rotate_stck(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (*stack && (*stack)->next)
	{
		ft_back_r(&tmp);
		*stack = (*stack)->next;
	}
	return ;
}

void	ft_rotate(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
	if (cmd[1] == 'a')
	{
		ft_rotate_stck(stack_a);
		write(1, "ra\n", 3);
	}
	else if (cmd[1] == 'b')
	{
		ft_rotate_stck(stack_b);
		write(1, "rb\n", 3);
	}
	else if (cmd[1] == 'r')
	{
		ft_rotate_stck(stack_a);
		ft_rotate_stck(stack_b);
		write(1, "rr\n", 3);
	}
	return ;
}
