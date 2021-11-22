#include <unistd.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

int	main(void)
{
	int	a = 10;
	int	*ptr;

	ptr = &a;
	printf("1. a = %d\n", a);
	ft_ft(ptr);
	printf("2. a = %d\n", a);
	return 0;
}
