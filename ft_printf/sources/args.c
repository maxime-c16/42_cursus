/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximecauchy <maximecauchy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:34:06 by maximecauch       #+#    #+#             */
/*   Updated: 2021/12/22 14:17:05 by maximecauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_is_c(char c)
{
	if (c == 'c')
		return (1);
	else
		return (0);
}

int	ft_is_s(char c)
{
	if (c == 's')
		return (1);
	else
		return (0);
}

int	ft_is_p(char c)
{
	if (c == 'p')
		return (1);
	else
		return (0);
}

int	ft_is_percent(char c)
{
	if (c == '%')
		return (1);
	return (0);
}

int	ft_is_args(char c)
{
	if (ft_is_c(c) || ft_is_d(c) || ft_is_i(c) || ft_is_p(c)
		|| ft_is_s(c) || ft_is_u(c) || ft_is_x(c)
		|| ft_is_percent(c) || ft_is_X(c))
		return (1);
	else
		return (0);
}
