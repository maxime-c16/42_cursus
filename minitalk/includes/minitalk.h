#ifndef MINITALK_H

# define MINITALK_H

# define BUFF_SIZE 1024

# include <signal.h>
# include <zconf.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_message
{
	char	message[BUFF_SIZE];
	int		bit;
	int		byte;
}			t_message;

#ifndef G_MSG
# define G_MSG
t_message	g_msg = {{0}, 1 << 6, 0};
#endif


char		*ft_itoa(int n);

#endif
