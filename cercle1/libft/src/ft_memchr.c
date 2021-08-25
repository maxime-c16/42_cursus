#include "../libft.h"

void	*ft_memchr(const void *s, int c, int n)
{
	unsigned char	*ptr;	
	int				i;
	unsigned char	a;

	i = 0;
	ptr = (unsigned char *)s;
	a = (unsigned char)c;
	while (i < n)
	{
		if (ptr[i] == a)
		{
			return (ptr + i);
		}
		i++;
	}
	return (NULL);
}
