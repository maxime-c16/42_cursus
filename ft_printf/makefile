SRCS 	=	sources/*.c *.c

OBJS 	=	$(SRCS:.c=.o)

NAME 	=	libftprintf.a

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

$(OBJS)	:
			gcc -Wall -Wextra -Werror -c $(SRCS)

clean	:
			/bin/rm -f $(OBJS)

fclean	:	clean
			/bin/rm -f $(NAME)

re 		:	fclean all
