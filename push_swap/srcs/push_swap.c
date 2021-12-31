#include "../includes/push_swap.h"

void	ft_exit(char *exit_msg, int exit_code)
{
	printf("%s", exit_msg);
	exit(exit_code);
	return ;
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac < 2)
		ft_exit("Too few arguments...\n", 1);
	return (0);
}
