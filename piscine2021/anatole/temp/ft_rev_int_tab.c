#include <unistd.h>
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	j = size - 1;
	i = 0;
	while (i < (size / 2))
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
		i++;
		j--;
	}
	return ;
}

int	main(void)
{
	int	tab[4] = {10, 20, 42, 65};
	int	i = 0;

	ft_rev_int_tab(tab, 4);
	while (i < 4)
		printf("%d\n", tab[i++]);
}
