/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximecauchy <maximecauchy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 09:01:39 by maximecauch       #+#    #+#             */
/*   Updated: 2021/09/22 17:31:19 by maximecauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static long	ft_len(long nb)
{
	long	size;

	size = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		size++;
	}
	while (nb > 0)
	{
		size++;
		nb = nb / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	len_n;
	long	len;

	len_n = (long)n;
	len = ft_len(len_n);
	str = (char *)malloc(sizeof(char) * (ft_len(len_n) + 1));
	if (!(str))
		return (NULL);
	str[len] = '\0';
	if (len_n == 0)
		str[0] = 0 + '0';
	if (len_n < 0)
	{
		str[0] = '-';
		len_n *= -1;
	}
	while (len_n > 0)
	{
		len--;
		str[len] = 48 + (len_n % 10);
		len_n /= 10;
	}
	return (str);
}
