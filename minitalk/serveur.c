/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:57:46 by mcauchy           #+#    #+#             */
/*   Updated: 2022/04/12 16:01:32 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len)
	{
		*ptr++ = (unsigned char)c;
		len--;
	}
	return (b);
}

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

void	main_handler(int sig)
{
	static int	i;
	static char	message[BUFF_SIZE];

	if (sig == SIGUSR1)
		message[i] |= (1 << g_msg.bit);
	else if (sig == SIGUSR2)
		message[i] &= ~(1 << g_msg.bit);
	g_msg.bit--;
	if (g_msg.bit == -1)
	{
		g_msg.bit = 7;
		if (message[i] == '\0')
		{
			write(1, &message, i);
			ft_memset(message, 0, BUFF_SIZE);
		}
		else
			i++;
	}
	return ;
}

int	main(void)
{
	ft_print_pid();
	while (1)
	{
		signal(SIGUSR1, main_handler);
		signal(SIGUSR2, main_handler);
	}
	return (0);
}
