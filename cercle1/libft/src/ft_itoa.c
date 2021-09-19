/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximecauchy <maximecauchy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 09:01:39 by maximecauch       #+#    #+#             */
/*   Updated: 2021/09/18 13:27:12 by maximecauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "limits.h"

int	ft_len(int nb)
{
	int	size;

	size = 0;
	if (nb == -2147483648)
		return (11);
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

char	*ft_intmin(char *str)
{
	str = "-2147483648\0";
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_len(n);
	if (!(str = (char *)malloc(sizeof(char) * (ft_len(n) + 1))))
		return (NULL);
	str[len] = '\0';
	if (n == -2147483648)
		return (ft_intmin(str));
	if (n == 0)
	{
		str = "0\0";
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		len--;
		str[len] = 48 + (n % 10);
		n /= 10;
	}
	return (str);
}

/*
int	main()
{
	printf("%s\n", ft_itoa(INT_MIN));
	return 0;
}
*/
