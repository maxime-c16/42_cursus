#include "../includes/push_swap.h"

void	ft_check_int(long nb)
{
	if (nb > INT_MAX || nb < INT_MIN)
		ft_exit("Int overflow\n", 1);
	return ;
}

void	ft_check_db(char **str)
{
	int	i;
	int	j;
	int nb;

	i = 0;
	while (str[i])
	{
		j = 0;
		nb = 0;
		while (str[j])
		{
			if (ft_strcmp(str[i], str[j]))
				nb++;
			j++;
		}
		if (nb > 1)
			ft_exit("Int repetition, check argv\n", 1);
	}
}

void	ft_parse_fill(t_stack **stack, char *str)
{
	char	**split;
	int		i;
	int		num;

	i = 0;
	split = ft_split(str, ' ');
	if (!split[1])
	{
		ft_init_lst(stack, ft_atoi(str));
		return ;
	}
	num = ft_atoi(split[i]);
	ft_init_lst(stack, num);
	i = 1;
	while (split[i + 1])
	{
		num = ft_atoi(split[i]);
		printf("num = %d\n", num);
		ft_check_int(num);
		ft_lstadd_back(stack, num);
		i++;
	}
	return ;
}

void	ft_parse_int(t_stack **stack, char **av, int ac)
{
	int	num;
	int	i;

	i = 1;
	num = (int)ft_atoi(av[i]);
	ft_init_lst(stack, num);
	while (++i < ac)
	{
		num = (int)ft_atoi(av[i]);
		ft_lstadd_back(stack, num);
	}
	return ;
}
