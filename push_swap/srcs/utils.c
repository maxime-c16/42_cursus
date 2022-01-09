#include "../includes/push_swap.h"

int	ft_db_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

char	**ft_normalize(char **str)
{
	int		i;
	int		j;
	int		size;
	char	**new;

	i = 0;
	size = ft_db_strlen(str);
	quicksort(str, 0, size - 2);
	new = malloc(sizeof(char *) * (size + 1));
	while (new[i])
	{
		j = 0;
		while (str[j])
		{
			if (new[i] == str[j])
				new[i] = ft_itoa(j);
			j++;
		}
		i++;
	}
	return (new);
}
