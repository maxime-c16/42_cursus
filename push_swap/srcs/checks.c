#include "../includes/push_swap.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i]
			|| (s1[i + 1] && !s2[i + 1])
			|| (!s1[i + 1] && s2[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_str_isalpha(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (ft_isalpha(str[i][j]) == 1)
				ft_exit("Arg error, check argv\n", 1);
			j++;
		}
		i++;
	}
	return ;
}

int	get_size(t_stack **stack)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = *stack;
	while (tmp->next)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
