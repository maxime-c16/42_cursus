FILES	=	push_swap.c ft_atoi.c checks.c ft_lsts.c ft_r_mouvement.c		\
			ft_p_mouvement.c parsing.c ft_split_ps.c ft_s_mouvement.c		\
			cases.c ft_rr_mouvement.c sorting_algo.c utils.c quick_sort.c	\
			ft_itoa_ps.c indexes.c

SRC_DIR	=	srcs/

SRCS	=	$(addprefix $(SRC_DIR), $(FILES))

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	push_swap

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $@ $^

norme	:
			@norminette $(CSRC) $(CHEADER) | sed "s,Norme,${ESC}[38;5;326m&${ESC}[0m," | sed "s/Error/  Error/g" | sed "s,Error,${ESC}[31m&${ESC}[0m,"

clean	:
			/bin/rm -f $(OBJS)

fclean	:	clean
			/bin/rm -f $(NAME)

re		:	fclean	all

