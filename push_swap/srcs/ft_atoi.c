/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximecauchy <maximecauchy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:42:19 by maximecauch       #+#    #+#             */
/*   Updated: 2022/03/31 21:42:20 by maximecauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atoi(const char *str)
{
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	while (*str && (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
			|| *str == '\r'
			|| *str == ' '))
		str++;
	if (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str) && *str)
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
