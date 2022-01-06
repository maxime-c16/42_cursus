#include "../includes/push_swap.h"

void	ft_check_int(long nb)
{
	if (nb > INT_MAX || nb < INT_MIN)
		ft_exit("Int overflow\n", 1);
	return ;
}

void	ft_parse_case(t_stack **stack, char *str)
{
	if (str[1] && str[1] == ' ')
		ft_parse_fill(stack, str);
	else
	{
		ft_check_int(ft_atoi(str[0]));
		ft_init_lst(stack, ft_atoi(str[0]));
	}
}

void	ft_parse_fill(t_stack **stack, char *str)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(str, ' ');
	ft_init_lst(stack, ft_atoi(split[i]));
	while (split[i++])
	{
		ft_check_int(ft_atoi(split[i]));
		ft_lstadd_back(stack, ft_atoi(split[i]));
	}
}
