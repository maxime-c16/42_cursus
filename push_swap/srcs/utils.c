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

/*void	ft_normalize(char)
{
	t_stack *temp;
	t_stack	*temp2;

	temp = *stack;
	while (temp)
	{
		temp2 = *stack;
		while (temp2)
		{

		}
	}
}*/
