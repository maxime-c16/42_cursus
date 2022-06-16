#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# define BUFF_SIZE 1
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
int	    ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src);
char	*ft_strjoin(char *s1, char *s2);

#endif
