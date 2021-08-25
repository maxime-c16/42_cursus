#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)dst;
	while (n)
	{
		*ptr++ = *(unsigned char *)src++;
		n--;
	}
	return (dst);
}
