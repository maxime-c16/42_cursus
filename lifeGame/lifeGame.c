#include "lifeGame.h"

int	main(int ac, char **av)
{
	lives	**tab;
	int		i;

	i = 1;
	tab = ft_fill_tab(tab);
	tab = parse_life(av[1], tab);
	tab = get_struc(tab);
	printf("\nNombres d'iterations :\t%d\n", i);
	ft_print_tab(tab);
	printf("\n\n\n\n");
	sleep(1);
	i++;
	while (true)
	{
		printf("\nNombres d'iterations :\t%d\n", i);
		i++;
		tab = get_changes(tab);
		ft_print_tab(tab);
		tab = get_struc(tab);
		sleep(1);
		printf("\n\n\n\n");
	}
	return (0);
}
