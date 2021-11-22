/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximecauchy <maximecauchy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:45:20 by maximecauch       #+#    #+#             */
/*   Updated: 2021/11/09 14:28:20 by maximecauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

char	*ft_right(char *str)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str && str[i] != '\n')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	while (str && str[i] != '\0')
	{
		dest[j] = str[i];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_left(char *str)
{
	char	*final;
	int		i;

	i = 0;
	while (str[i] != '\n')
		i++;
	final = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!final)
		return (NULL);
	i = 0;
	while (str[i] != '\n')
	{
		final[i] = str[i];
		i++;
	}
	final[i] = '\0';
	return (final);
}

char	*get_nxt_line(int fd)
{
	static char	*str;
	int			ret;
	char		*buffer;
	char		*temp;
	char		*line;

	ret = BUFF_SIZE;
	str = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!str)
		return (NULL);
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFF_SIZE);
		buffer[BUFF_SIZE] = '\0';
		temp = str;
		str = ft_strjoin(str, buffer);
		free(temp);
		if (ft_strchr(str, '\n'))
			break;
	}
	line = ft_left(str);
	temp = str;
	str = ft_right(temp);
	free(temp);
	return (line);
}

int	main()
{
	int		fd;
	char	*line;

	fd = open("gnlTester/files/multiple_line_no_nl", 0);
	while ((line = get_nxt_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
