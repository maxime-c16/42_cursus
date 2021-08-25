#include "../libft.h"

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
