FILES   =       so_long.c parsing.c ft_itoa.c utils.c

GNLFILE =       get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRC_DIR =       srcs/

SRCS    =       $(addprefix $(SRC_DIR), $(FILES))

OBJS    =       $(SRCS:.c=.o) $(GNLFILE:.c=.o)

CC      =       clang

CFLAGS  =       -Wall -Wextra -Werror

DEBUG   =       -g3

NAME    =       so_long

HEADER  =       includes/so_long.h

all             :       $(NAME)

$(NAME) :   $(OBJS)
			$(CC) $^ $(CFLAGS) $(DEBUG) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g -o $@

macos   :       $(OBJS)
				$(CC) $^ $(CFLAGS) $(DEBUG) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

test    :
				./$(NAME)

clean   :
				/bin/rm -f $(OBJS)

fclean  :       clean
				/bin/rm -f $(NAME)

re		:       fclean  all

remacos :       fclean  macos

.PHONY  : all clean fclean fclean re