/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:45:29 by mcauchy           #+#    #+#             */
/*   Updated: 2022/03/31 21:45:30 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max_bits(int nb)
{
	int	i;

	i = 0;
	while (nb >> i)
		i++;
	return (i);
}

void	ft_putback_in_stck(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
		ft_exec_cmd("pa", stack_a, stack_b);
}

void	ft_last_rotate_on_stck(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = get_minimum(stack_a);
	while ((*stack_a)->num != min)
		ft_exec_cmd("ra", stack_a, stack_b);
	return ;
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, \
					t_stack *temp1)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	temp1 = NULL;
	size = get_size(stack_a);
	max_bits = get_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size + 1)
		{
			temp1 = *stack_a;
			if (((temp1->index >> i) & 1) == 1)
				ft_exec_cmd("ra", stack_a, stack_b);
			else
				ft_exec_cmd("pb", stack_a, stack_b);
			++j;
		}
		ft_putback_in_stck(stack_a, stack_b);
		++i;
	}
	ft_last_rotate_on_stck(stack_a, stack_b);
}
