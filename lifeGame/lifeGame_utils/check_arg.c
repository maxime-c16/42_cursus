#include "../lifeGame.h"

int	check_arg(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	if (i % 2 == 1)
		return (0);
	i = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j] - '0') == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//write down a string of 10 '0'


