#include "../includes/push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return ;
}

void	ft_normalize(char **str)
{
	int	*tab;

	ft_char_to_tab(str, &tab);
	quicksort(tab, 0, sizeof(tab) / 4);
	return ;
}
