FILES	=	push_swap.c

SRC_DIR	=	srcs/

SRCS	=	$(addprefix $(SRC_DIR), $(FILES))

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	push_swap

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) -fsanitize=address -o $@ $^

clean	:
			/bin/rm -f $(OBJS)

fclean	:	clean
			/bin/rm -f $(NAME)

re		:	fclean	all

