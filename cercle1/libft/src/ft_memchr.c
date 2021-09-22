/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximecauchy <maximecauchy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:31:57 by maximecauch       #+#    #+#             */
/*   Updated: 2021/09/22 17:31:58 by maximecauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, int n)
{
	unsigned char	*ptr;
	int				i;
	unsigned char	a;

	i = 0;
	ptr = (unsigned char *)s;
	a = (unsigned char)c;
	while (i < n)
	{
		if (ptr[i] == a)
		{
			return (ptr + i);
		}
		i++;
	}
	return (NULL);
}
