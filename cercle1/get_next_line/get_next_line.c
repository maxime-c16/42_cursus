#include "libft/libft.h"
#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!s3)
		return (NULL);
	s3 = strcat(s3, (char *)s1);
	s3 = strcat(s3, (char *)s2);
	return (s3);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)s;
	while (ptr[i])
	{
		if (ptr[i] == (char)c)
			return (ptr + i);
		i++;
	}
	if ((char)c == '\0')
		return (ptr + i);
	else
		return (NULL);
}

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

int	get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	char		*temp;
	int			ret;
	char		buffer[BUFF_SIZE + 1];

	ret = BUFF_SIZE;
	if (!str)
		str = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (fd <= 0 || !line)
		return (-1);
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
	*line = ft_gauche(str);
	temp = str;
	str = ft_droite(temp);
	free(temp);
	return (ret);
}

int	main(void)
{
	int		fd;
	int		ret;
	char	*line;
	int i = 0;

	fd = open("alternate_line_nl_with_nl", 0);
	ret = get_next_line(fd, &line);
	while (i++ < 1)
	{
		ret = get_next_line(fd, &line);
		printf("%s\n", line);
	}
	return (0);
}
