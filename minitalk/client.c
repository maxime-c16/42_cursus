/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:57:25 by mcauchy           #+#    #+#             */
/*   Updated: 2022/04/29 13:19:55 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	ft_msg_to_parent(int PID, char c)
{
	int	i;

	i = 7;
	while (i != -1)
	{
		if (c & (1 << i))
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
		i--;
		usleep(100);
	}
}

void	main_handler(char *PID, char *msg)
{
	int	pid;
	int	i;

	i = 0;
	pid = atoi(PID);
	while (msg[i])
	{
		ft_msg_to_parent(pid, msg[i]);
		i++;
	}
	ft_msg_to_parent(pid, '\0');
}

int	main(int ac, char **av)
{
	if (ac > 3)
	{
		printf("Arg error, check argv.\n");
		exit(1);
	}
	main_handler(av[1], av[2]);
	return (0);
}
