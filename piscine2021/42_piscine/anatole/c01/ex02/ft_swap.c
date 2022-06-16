#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	main(void)
{
	int a;
	int b;
	int *ptra;
	int *ptrb;

	a = 1;
	b = 34;
	ptra = &a;
	ptrb = &b;
	ft_swap(ptra, ptrb);
	printf("%d\n%d\n", a, b);
	return (0);
}

