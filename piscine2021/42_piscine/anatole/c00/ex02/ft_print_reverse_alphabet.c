#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	zemmour;

	zemmour = 'z';
	while (zemmour >= 'a')
	{
		write(1, &zemmour, 1);
		zemmour--;
	}
}

