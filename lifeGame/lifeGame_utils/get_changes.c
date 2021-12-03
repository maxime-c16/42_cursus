#include "../lifeGame.h"

int	check_survive(lives	cell)
{
	int	res;

	res = 0;
	if (cell.leftCell == ALIVE_SYMBOL)
		res++;
	if (cell.rightCell == ALIVE_SYMBOL)
		res++;
	if (cell.dwnCell == ALIVE_SYMBOL)
		res++;
	if (cell.upCell == ALIVE_SYMBOL)
		res++;
	if (cell.ldCell == ALIVE_SYMBOL)
		res++;
	if (cell.luCell == ALIVE_SYMBOL)
		res++;
	if (cell.rdCell == ALIVE_SYMBOL)
		res++;
	if (cell.ruCell == ALIVE_SYMBOL)
		res++;
	return (res);
}

lives	**get_changes(lives **tab)
{
	int	res;

	res = 0;
	for (int i = 0; i < WINDOW_SIZE; i++)
	{
		for (int j = 0; j < WINDOW_SIZE; j++)
		{
			res = check_survive(tab[i][j]);
			if (tab[i][j].state == ALIVE_SYMBOL)
			{
				if (res > 3 || res < 2)
					tab[i][j].state = DEATH_SYMBOL;
				else
					tab[i][j].state = ALIVE_SYMBOL;
			}
			else if (tab[i][j].state == DEATH_SYMBOL)
			{
				if (res == 3)
					tab[i][j].state = ALIVE_SYMBOL;
			}
		}
	}
	return (tab);
}
