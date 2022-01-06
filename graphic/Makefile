SRCS 	=	graphic.c

OBJ		=	${SRC:%.c=%.o}

CC		=	gcc

NAME 	=	graphic

all		:	$(NAME)

$(OBJ)	:	$(NAME)
			$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

fclean	:	clean
			/bin/rm -f $(NAME)

re 		:	fclean all
