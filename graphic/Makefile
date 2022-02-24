SRCS 	=	graphic.c

OBJ		=	${SRC:%.c=%.o}

CC		=	gcc

NAME 	=	graphic

all		:	$(NAME)

$(OBJ)	:	$(NAME)
			$(CC) -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext $< -o $@

fclean	:	clean
			/bin/rm -f $(NAME)

re 		:	fclean all
