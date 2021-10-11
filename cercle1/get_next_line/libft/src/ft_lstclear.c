/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximecauchy <maximecauchy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:17:43 by maximecauch       #+#    #+#             */
/*   Updated: 2021/08/23 13:42:48 by maximecauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **alst, void (*del)(void *))
{
	t_list	*ptr;

	if (!del || !alst || !*alst)
		return ;
	while (*alst && alst)
	{
		ptr = (*alst)->next;
		ft_lstdelone(*alst, del);
		*alst = ptr;
	}
	return ;
}
