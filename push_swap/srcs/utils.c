/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:45:33 by mcauchy           #+#    #+#             */
/*   Updated: 2022/03/31 21:45:34 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_db_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return ;
}

int	get_minimum(t_stack **stack)
{
	t_stack	*temp;
	int		temp2;

	temp = *stack;
	temp2 = (*stack)->num;
	while (temp && temp->next)
	{
		if (temp2 > temp->num)
			temp2 = temp->num;
		temp = temp->next;
	}
	return (temp2);
}
