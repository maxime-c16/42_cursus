#make a makefile like push_swap/Makefile but with lifegame .c files instead of push_swap .c files

SRCS		=	lifeGame.c lifeGame_utils/check_arg.c lifeGame_utils/ft_split.c \
				lifeGame_utils/get_changes.c lifeGame_utils/get_grid.c \
				lifeGame_utils/get_struct.c

NAME		=	lifeGame

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=

all			:	$(NAME)

$(NAME)	:	$(OBJS)
				$(CC) -o $@ $^

clean		:
				/bin/rm -f $(OBJS)

fclean		:	clean
				/bin/rm -f $(NAME)

re			:	fclean	all

