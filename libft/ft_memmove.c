/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximecauchy <maximecauchy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:51:12 by maximecauch       #+#    #+#             */
/*   Updated: 2021/08/06 16:02:29 by maximecauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst > src)
		while (len--)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
