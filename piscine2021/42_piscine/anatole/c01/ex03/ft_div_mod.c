#include <unistd.h>
#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int	main(void)
{
	int	a;
	int	b;
	int	*div;
	int	*mod;
	int	c;
	int	d;

	div = &c;
	mod = &d;
	a = 10;
	b = 5;
	ft_div_mod(a, b, div, mod);
	printf("%d\n%d\n", c, d);
	return (0);
}
