/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximecauchy <maximecauchy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:41:07 by maximecauch       #+#    #+#             */
/*   Updated: 2022/01/06 09:50:33 by maximecauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	word_count(char const *s, char c)
{
	int		wd;
	int		i;

	i = 0;
	wd = 0;
	if (s[0] != c)
		wd++;
	while (s[++i])
	{
		if (s[i] != c && s[i - 1] == c)
			wd++;
	}
	return (wd);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		ind;
	char	*tmp;
	char	**tab;

	i = -1;
	ind = -1;
	tab = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!s || !tab)
		return (NULL);
	while (s[++i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			j = 0;
			while (s[i + j] && s[i + j] != c)
				j++;
			tmp = ft_substr(s, i, j);
			tab[++ind] = tmp;
			i += j - 1;
		}
	}
	return (tab);
}
