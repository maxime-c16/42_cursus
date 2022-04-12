/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_mouvement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:43:21 by maximecauch       #+#    #+#             */
/*   Updated: 2022/04/02 01:26:25 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = NULL;
	if (cmd[1] == 'a')
	{
		ft_push_stck(stack_b, stack_a, tmp);
		write(1, "pa\n", 3);
	}
	else if (cmd[1] == 'b')
	{
		ft_push_stck(stack_a, stack_b, tmp);
		write(1, "pb\n", 3);
	}
	return ;
}

void	ft_del_one(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (*stack && (*stack)->next)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else if (*stack && !(*stack)->next)
		*stack = NULL;
	free(tmp);
	return ;
}

void	ft_push_stck(t_stack **stack_a, t_stack **stack_b, t_stack *tmp)
{
	int	index;

	index = (*stack_a)->index;
	tmp = ft_lstnew((*stack_a)->num, index);
	if (!*stack_b && *stack_a)
	{
		(*stack_b) = tmp;
		ft_del_one(stack_a);
	}
	else if (*stack_b && *stack_a)
	{
		ft_lstadd_front(stack_b, tmp);
		ft_del_one(stack_a);
	}
	return ;
}
