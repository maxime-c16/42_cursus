/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximecauchy <maximecauchy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:10:59 by mcauchy           #+#    #+#             */
/*   Updated: 2021/12/12 13:08:25 by maximecauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_left(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	if (*str == 0)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	temp = malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		temp[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		temp[i] = '\n';
		i++;
	}
	temp[i] = 0;
	return (temp);
}

char	*ft_read(int fd, char *str)
{
	char	*buffer;
	int		len_read;

	buffer = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buffer)
		return (NULL);
	len_read = 1;
	while (len_read && !ft_strchr(str, '\n'))
	{
		len_read = read(fd, buffer, BUFF_SIZE);
		if (len_read == -1)
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		buffer[len_read] = 0;
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*ft_static_right(char *str)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	cpy = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!cpy)
		return (NULL);
	i++;
	while (str[i])
		cpy[j++] = str[i++];
	cpy[j] = 0;
	free(str);
	return (cpy);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*ret;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (0);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	ret = ft_left(str);
	str = ft_static_right(str);
	return (ret);
}
