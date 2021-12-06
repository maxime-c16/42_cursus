#include "../lifeGame.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_get_size_parse(const char *str)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			cnt++;
		i++;
	}
	return (cnt);
}

lives	**parse_life(const char *str, lives **tab)
{
	int		i;
	int		odd;
	int		x;
	int		y;
	char	**buffer;

	i = 0;
	x = 0;
	y = 0;
	odd = 0;
	buffer = ft_split((char *)str, ". ");
	while (buffer[i])
	{
		if (odd % 2 == 0)
		{
			x = atoi(buffer[i]);
			odd++;
		}
		else if (odd % 2 == 1)
		{
			y = atoi(buffer[i]);
			odd++;
			tab[x][y].state = ALIVE_SYMBOL;
		}
		i++;
	}
	return (tab);
}

void	*ft_calloc(size_t count, size_t size)
{
	lives	*mem;

	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	return (mem);
}

lives	**ft_fill_tab(lives **tab)
{
	tab = ft_calloc(WINDOW_SIZE + 1, sizeof(lives *));
	for (int i = 0; i < WINDOW_SIZE; i++)
	{
		tab[i] = ft_calloc(WINDOW_SIZE + 1, sizeof(lives));
		for (int j = 0; j < WINDOW_SIZE; j++)
			tab[i][j].state = DEATH_SYMBOL;
	}
	return (tab);
}

void	ft_print_tab(lives **tab)
{
	for (int i = 0; i < WINDOW_SIZE; i++)
	{
		for (int j = 0; j < WINDOW_SIZE; j++)
			printf(" %c ",tab[i][j].state);
		printf("\n");
	}
}
