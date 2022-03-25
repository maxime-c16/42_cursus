cyan = /bin/echo -e "\x1b[36m\#\# $1\x1b[0m"
green = /bin/echo -e "\x1b[32m\#\# $1\x1b[0m"
red = /bin/echo -e "\x1b[31m\#\# $1\x1b[0m"
yellow = /bin/echo -e "\x1b[33m\#\# $1\x1b[0m"
blue = /bin/echo -e "\x1b[34m\#\# $1\x1b[0m"
purple = /bin/echo -e "\x1b[35m\#\# $1\x1b[0m"
grey = /bin/echo -e "\x1b[30m\#\# $1\x1b[0m"
SRCS 	=	graphic.c

OBJ		=	${SRC:%.c=%.o}

CC		=	gcc

NAME 	=	graphic

all		:	$(NAME)

$(OBJ)	:	$(NAME)
			@$(call cyan, $(CC) -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext $< -o $@)

fclean	:	clean
			/bin/rm -f $(NAME)

re 		:	fclean all


