/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:00:55 by mcauchy           #+#    #+#             */
/*   Updated: 2022/05/21 22:54:10 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# define BUFF_SIZE 102400

# include <signal.h>
# include <zconf.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
#include <dlfcn.h>
#include <execinfo.h>

char		*ft_itoa(int n);

typedef struct s_message
{
	int		bit;
	int		byte;
	int		buffer_overflow;
}			t_message;

#ifndef G_MSG

# define G_MSG

t_message	g_msg = {7, 0, 0};

#endif

#endif
