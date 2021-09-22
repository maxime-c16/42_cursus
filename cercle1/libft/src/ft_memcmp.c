/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximecauchy <maximecauchy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:32:01 by maximecauch       #+#    #+#             */
/*   Updated: 2021/09/22 17:32:02 by maximecauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, int n)
{
	int	cmp;

	while (n)
	{
		cmp = *(unsigned char *)s1++ - *(unsigned char *)s2++;
		if (cmp)
			return (cmp);
		n--;
	}
	return (0);
}
