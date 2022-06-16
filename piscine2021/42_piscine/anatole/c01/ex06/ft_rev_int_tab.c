#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i != size/2)
	{
		ft_swap(&tab[i], &tab[size - i - 1]); 
		i++;
	}
}

int	main(void)
{
	int	tab[4] = {10, 20, 42, 65};
	int	i = 0;

	ft_rev_int_tab(tab, 4);
	while (i < 4)
		printf("%d\n", tab[i++]);
}
