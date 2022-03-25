#include "../lifeGame.h"

lives	pos_x(lives pos, int x, int y, lives **tab)
{
	if (x == 0)
	{
		pos.leftCell = DEATH_SYMBOL;
		pos.ldCell = DEATH_SYMBOL;
		pos.luCell = DEATH_SYMBOL;
		pos.rightCell = tab[x + 1][y].state;
		pos.rdCell = tab[x + 1][y + 1].state;
		pos.ruCell = tab[x + 1][y - 1].state;
		pos.dwnCell = tab[x][y + 1].state;
		pos.upCell = tab[x][y - 1].state;
	}
	else if (x == WINDOW_SIZE - 1)
	{
		pos.rightCell = DEATH_SYMBOL;
		pos.ruCell = DEATH_SYMBOL;
		pos.rdCell = DEATH_SYMBOL;
		pos.upCell = tab[x][y - 1].state;
		pos.leftCell = tab[x - 1][y].state;
		pos.ldCell = tab[x - 1][y + 1].state;
		pos.dwnCell = tab[x][y + 1].state;
		pos.luCell = tab[x - 1][y - 1].state;
	}
	return (pos);
}

lives	pos_y(lives pos, int x, int y, lives **tab)
{
	if (y == 0)
	{
		pos.upCell = DEATH_SYMBOL;
		pos.luCell = DEATH_SYMBOL;
		pos.ruCell = DEATH_SYMBOL;
		pos.leftCell = tab[x - 1][y].state;
		pos.ldCell = tab[x - 1][y + 1].state;
		pos.rightCell = tab[x + 1][y].state;
		pos.rdCell = tab[x + 1][y + 1].state;
		pos.dwnCell = tab[x][y + 1].state;
	}
	else if (y == WINDOW_SIZE - 1)
	{
		pos.dwnCell = DEATH_SYMBOL;
		pos.ldCell = DEATH_SYMBOL;
		pos.rdCell = DEATH_SYMBOL;
		pos.upCell = tab[x][y - 1].state;
		pos.luCell = tab[x - 1][y - 1].state;
		pos.leftCell = tab[x - 1][y].state;
		pos.rightCell = tab[x + 1][y].state;
		pos.ruCell = tab[x + 1][y - 1].state;
	}
	return (pos);
}

lives	get_pos(lives pos, unsigned int x, unsigned int y, lives **tab)
{
	if (x == 0 || x == WINDOW_SIZE - 1)
		return (pos_x(pos, x, y, tab));
	if (y == 0 || y == WINDOW_SIZE - 1)
		return (pos_y(pos, x, y, tab));
	pos.rightCell = tab[x + 1][y].state;
	pos.rdCell = tab[x + 1][y + 1].state;
	pos.ruCell = tab[x + 1][y - 1].state;
	pos.upCell = tab[x][y - 1].state;
	pos.luCell = tab[x - 1][y - 1].state;
	pos.leftCell = tab[x - 1][y].state;
	pos.ldCell = tab[x - 1][y + 1].state;
	pos.dwnCell = tab[x][y + 1].state;
	return (pos);
}

lives	**get_struc(lives **tab)
{
	int		cmp;
	lives	cpy;
	lives	**new;

	new = tab;
	cmp = 0;
	for (unsigned int x = 0; x < WINDOW_SIZE; x++)
	{
		for (unsigned int y = 0; y < WINDOW_SIZE; y++)
		{
			printf("test\n");
			cpy.state = new[x][y].state;
			new[x][y] = get_pos(new[x][y], x, y, new);
			if (cpy.state == new[x][y].state)
				cmp++;
		}
	}
	free(tab);
	return (new);
}
