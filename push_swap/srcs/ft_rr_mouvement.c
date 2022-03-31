/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr_mouvement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximecauchy <maximecauchy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:43:31 by maximecauch       #+#    #+#             */
/*   Updated: 2022/03/31 21:43:32 by maximecauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate_rr_stck(t_stack **stack)
{
	t_stack	*tmp;

	tmp = ft_lstlast(stack);
	tmp->prev->next = NULL;
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
