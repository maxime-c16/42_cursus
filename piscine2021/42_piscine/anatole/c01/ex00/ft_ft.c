#include <unistd.h>
#include <stdio.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

int	main(void)
{
	int	a;
	int *ptr;

	a = 1;
	ptr = &a;

	ft_ft(ptr);
	printf("%d\n", a);
	return (0);
}
