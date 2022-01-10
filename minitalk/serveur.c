#include "includes/minitalk.h"

void	ft_exit(char *str)
{
	write(2, str, strlen(str));
}

void	ft_print_pid(void)
{
	char	*PID;

	PID = ft_itoa(getpid());
	write(1, "PID : ", 6);
	write(1, PID, strlen(PID));
	write(1, "\n", 1);
	free(PID);
}

int	main()
{
	struct sigaction	action;
	struct sigaction	tmp;

	action.sa_flags = SA_SIGINFO;
	tmp.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &action, NULL) != 0)
		ft_exit("signal error\n");
	if (sigaction(SIGUSR2, &tmp, NULL) != 0)
		ft_exit("signal error");
	ft_print_pid();
}
