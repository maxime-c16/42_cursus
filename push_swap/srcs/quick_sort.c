#include "../includes/push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
	return ;
}

int	ft_pivot(int *tab, int low, int high)
{
	int	i;
	int	j;
	int	pivot;

	i = low - 1;
	j = low;
	pivot = tab[high];
	while (j < high)
	{
		if (tab[j] < pivot)
		{
			i++;
			ft_swap(&tab[i], &tab[j]);
		}
		j++;
	}
	i++;
	ft_swap(&tab[i], &tab[high]);
	return (i);
}

void	quicksort(int *tab, int low, int high)
{
	int	pivotIndex;

	if (low < high)
	{
		pivotIndex = ft_pivot(tab, low, high);
		quicksort(tab, low, pivotIndex - 1);
		quicksort(tab, pivotIndex + 1, high);
	}
	return ;
}

void	ft_char_to_tab(char **str, int **tab)
{
	int	i;

	i = 0;
	while (str[i])
	{
		*(tab + i) = (int)ft_atoi(str[i]);
		i++;
	}
}
