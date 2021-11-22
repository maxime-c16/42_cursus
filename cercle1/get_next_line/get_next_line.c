/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximecauchy <maximecauchy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:54:35 by maximecauch       #+#    #+#             */
/*   Updated: 2021/10/26 21:53:51 by maximecauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

char	*ft_gauche(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_droite(char *str)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!dest)
		return (NULL);
	while (str[i] && str[i] != '\0')
		dest[j++] = str[++i];
	dest[j] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*temp;
	int			ret;
	char		buffer[BUFF_SIZE + 1];
	char		*line = (char *)malloc(sizeof(char) * 100);

	ret = BUFF_SIZE;
	if (!str)
		str = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (fd <= 0 || !str)
		return (NULL);
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFF_SIZE);
		buffer[BUFF_SIZE] = '\0';
		temp = str;
		str = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(str, '\n'))
			break ;
	}
	line = ft_gauche(str);
	temp = str;
	str = ft_droite(temp);
	free(temp);
	return (line);
}

int	main()
{
	int		fd;
	char	*line;

	fd = open("gnlTester/files/multiple_line_no_nl", 0);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
