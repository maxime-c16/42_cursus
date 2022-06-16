SRCS 	=	sources/args_int.c \
			sources/args.c \
			sources/ft_int.c \
			sources/ft_putarg.c \
			sources/ft_putchar.c \
			sources/ft_str.c \
			sources/printf_utils.c

OBJS 	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME 	=	libftprintf.a

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

clean	:
			/bin/rm -f $(OBJS)

fclean	:	clean
			/bin/rm -f $(NAME)

re 		:	fclean all
