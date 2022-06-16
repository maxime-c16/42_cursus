#include <unistd.h>
#include <stdio.h>

char	*ft_strncpy(char *dst, char *src, unsigned int n)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i != n)
	{
		dst[i] = src[i];
		i++;
	}
	while (dst[i] != '\0')
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

int	main(void)
{
	char	*dst;
	char	*src;

	src = "anatole";
	dst = malloc(sizeof(char) * (8 + 1));
	if (!dst)
		return (0);
	dst = ft_strncpy(dst, src, 11);
	printf("%c\n", dst[10]);
	return (0);
}
