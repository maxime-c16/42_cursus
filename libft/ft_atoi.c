/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximecauchy <maximecauchy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 12:54:51 by maximecauch       #+#    #+#             */
/*   Updated: 2021/11/11 14:56:10 by maximecauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*str && (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
			|| *str == '\r'
			|| *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str) && *str)
	{
		if (result > 2147483647 && sign > 0)
			return (-1);
		if (result >= 2147483648 && sign < 0)
			return (0);
		result = result * 10 + (*str - '0');
		str++;
	}
	return ((int)result * sign);
}
