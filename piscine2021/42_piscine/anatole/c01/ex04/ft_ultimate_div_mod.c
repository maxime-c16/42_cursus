#include <unistd.h>
#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *a / *b;
	*b = c % *b;
	return ;
}

int	main(void)
{
	int	a;
	int	b;
	int *ptra;
	int	*ptrb;

	a = 10;
	b = 2;
	ptra = &a;
	ptrb = &b;
	ft_ultimate_div_mod(ptra, ptrb);
	printf("%d\n%d\n", a, b);
	return (0);
}
