#include "includes/minitalk.h"

void	ft_exit(char *str)
{
	write(2, str, strlen(str));
}

void	ft_print_pid(void)
{
	int	PID;

	PID = getpid();
	printf("PID : %d\n", PID);
	return ;
}

void	main_handler(void)
{
	while (1)
	{
		pause();
		if (g_msg.msg_status || g_msg.buffer_overflow)
		{
			write(1, g_msg.message, strlen(g_msg.message));
			g_msg.byte = 0;
			g_msg.bit = 1 << 6;
			if (g_msg.msg_status)
				write(1, "\n", 1);
			g_msg.msg_status = 0;
			g_msg.buffer_overflow = 0;
		}
	}
}

int	main(void)
{
	struct sigaction	action;
	struct sigaction	tmp;

	action.sa_sigaction = 
	action.sa_flags = SA_SIGINFO;
	tmp.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &action, NULL) != 0)
		ft_exit("signal error\n");
	if (sigaction(SIGUSR2, &tmp, NULL) != 0)
		ft_exit("signal error");
	ft_print_pid();
	main_handler();
	return (0);
}
