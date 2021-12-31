#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
	return ;
}

int	ft_pivot(int tab[], int low, int high)
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

void	quicksort(int tab[], int low, int high)
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

void	ft_print_tab(int tab[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf(" %d ", tab[i]);
		i++;
	}
	return ;
}

int	main(void)
{
	int	tab[10] = {-6, 5, 1, -1, 3, 20, 42, 18, 10, 7};

	printf("\t\tUnsorted array :\n\n\n");
	ft_print_tab(tab, sizeof(tab) / sizeof(tab[0]));
	printf("\n\n\n");
	printf("\t\tsorted array :\n\n\n");
	quicksort(tab, 0, sizeof(tab) / sizeof(tab[0]));
	ft_print_tab(tab, sizeof(tab) / sizeof(tab[0]));
	return 0;
}
