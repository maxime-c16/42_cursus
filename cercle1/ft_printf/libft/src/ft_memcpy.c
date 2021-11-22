/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximecauchy <maximecauchy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:32:05 by maximecauch       #+#    #+#             */
/*   Updated: 2021/11/11 14:34:10 by maximecauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*temp;

	ptr = (unsigned char *)dst;
	temp = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	while (n)
	{
		*ptr++ = *temp++;
		n--;
	}
	return (dst);
}
