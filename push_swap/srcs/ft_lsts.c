/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:42:59 by maximecauch       #+#    #+#             */
/*   Updated: 2022/03/31 21:45:59 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init_lst(t_stack **stack, long nb)
{
	*stack = (t_stack *)malloc(sizeof(*stack));
	if (*stack == NULL)
		ft_exit("Malloc error\n", 1);
	(*stack)->num = nb;
	(*stack)->next = NULL;
	(*stack)->prev = NULL;
	return ;
}

t_stack	*ft_lstnew(int num, int index)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(*new));
	if (new == NULL)
		ft_exit("Malloc error", 1);
	new->num = num;
	new->index = index;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*ft_lstlast(t_stack **lst)
{
	t_stack	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (!(tmp->next))
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

void	ft_lstadd_back(t_stack **stack, int nb, int index)
{
	t_stack	*tmp;
	t_stack	*cpy;

	tmp = ft_lstnew(nb, index);
	tmp->index = index;
	cpy = *stack;
	if (cpy == NULL)
		ft_exit("stack is empty\n", 1);
	while (cpy->next)
		cpy = cpy->next;
	cpy->next = tmp;
	tmp->prev = cpy;
	return ;
}

void	ft_lstadd_front(t_stack **stack, t_stack *elem)
{
	if (*stack)
		elem->next = *stack;
	*stack = elem;
	return ;
}
