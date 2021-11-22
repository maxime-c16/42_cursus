#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# define BUFF_SIZE 1
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

char	*get_next_line(int fd);

#endif
