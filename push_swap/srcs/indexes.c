/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:41:42 by maximecauch       #+#    #+#             */
/*   Updated: 2022/03/31 21:45:01 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_index(char **cpy, int num)
{
	int	i;

	i = 0;
	while (cpy[i])
	{
		if (ft_atoi(cpy[i]) == num)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_init_index(t_stack **stack, char **cpy)
{
	int		size;
	t_stack	*temp;

	size = get_size(stack);
	temp = *stack;
	quicksort(cpy, 0, size);
	while (temp)
	{
		temp->index = ft_get_index(cpy, temp->num);
		if (temp->index == -1)
			ft_exit("Error: index not found\n", 1);
		temp = temp->next;
	}
}
