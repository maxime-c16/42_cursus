#include "includes/minitalk.h"

void	ft_sigusr(int sig)
{
	(void)sig;
	printf("Message received.\n");
}

void	ft_msg_to_parent(int PID, char c)
{
	int	i;

	i = 1 << 6;
	while (i)
	{
		if (c & i)
		{
			if (kill(PID, SIGUSR1) == -1)
			{
				printf("SIG ERROR.\n");
				exit(1);
			}
		}
		else
		{
			if (kill(PID, SIGUSR2) == -1)
			{
				printf("SIG EROOR.\n");
				exit(1);
			}
		}
		i = i >> 1;
		usleep(500);
	}
}

void	main_handler(char *PID, char *msg)
{
	int	pid;

	pid = atoi(PID);
	while (*msg)
	{
		ft_msg_to_parent(pid, *msg);
		msg++;
	}
	ft_msg_to_parent(pid, *msg);
}

int	main(int ac, char **av)
{
	if (ac > 3)
	{
		printf("Arg error, check argv.\n");
		exit(1);
	}
	signal(SIGUSR1, ft_sigusr);
	main_handler(av[1], av[2]);
	return (0);
}
