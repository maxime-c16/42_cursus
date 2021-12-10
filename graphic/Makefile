SRCS 	=	*.c

OBJS	=	${SRC:%.c=%.o}

NAME 	=	graphic

all		:	$(NAME)

$(OBJS)	:
			gcc -Wall -Werror -Wextra -std=gnu99 -I. -g -lm -lGLEW -lglfw -lGL ${OBJS} minilibx/libmlx_Linux.a -o ${NAME}

clean	:
			/bin/rm -f $(OBJS)

fclean	:	clean
			/bin/rm -f $(NAME)

re 		:	fclean all
