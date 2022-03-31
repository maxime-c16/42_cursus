#include "../includes/push_swap.h"

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
	return ;
}

int	ft_pivot(char **tab, int low, int high)
{
	int	i;
	int	j;
	int	pivot;
	int	num;

	i = low - 1;
	j = low;
	num = 0;
	pivot = ft_atoi(tab[high]);
	while (j < high)
	{
		num = ft_atoi(tab[j]);
		if (num < pivot)
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

void	quicksort(char	**tab, int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = ft_pivot(tab, low, high);
		quicksort(tab, low, pivot_index - 1);
		quicksort(tab, pivot_index + 1, high);
	}
	return ;
}
