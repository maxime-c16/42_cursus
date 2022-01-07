FILES	=	push_swap.c ft_atoi.c checks.c ft_lsts.c ft_r_mouvement.c \
			ft_p_mouvement.c parsing.c ft_split_ps.c ft_s_mouvement.c \
			cases.c

SRC_DIR	=	srcs/

SRCS	=	$(addprefix $(SRC_DIR), $(FILES))

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	

NAME	=	push_swap

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC)  -fsanitize=address -o $@ $^

clean	:
			/bin/rm -f $(OBJS)

fclean	:	clean
			/bin/rm -f $(NAME)

re		:	fclean	all

