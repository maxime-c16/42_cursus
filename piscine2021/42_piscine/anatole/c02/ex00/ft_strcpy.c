#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, str + i, 1);
		i++;
	}
	return ;
}

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	main(void)
{
	char	*dst;
	char	*src;

	src = "anatole";
	dst = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dst)
		return (0);
	dst = ft_strcpy(dst, src);
	ft_putstr(dst);
	return (0);
}
