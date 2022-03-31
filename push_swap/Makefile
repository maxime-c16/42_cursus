FILES	=	push_swap.c ft_atoi.c checks.c ft_lsts.c ft_r_mouvement.c		\
			ft_p_mouvement.c parsing.c ft_split_ps.c ft_s_mouvement.c		\
			cases.c ft_rr_mouvement.c sorting_algo.c utils.c quick_sort.c	\
			ft_itoa_ps.c

SRC_DIR	=	srcs/

SRCS	=	$(addprefix $(SRC_DIR), $(FILES))

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=

NAME	=	push_swap

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) -o $@ $^

target:
	number=1 ; while [[ $$number -le 111 ]] ; do \
		ARG=`ruby -e "puts (-$$number...$$number).to_a.shuffle.join(' ')"` ; \
		./push_swap $$ARG; \
		((number = number + 10)) ; \
	done

#generate a list of random numbers using ruby

NUMBERS = `ruby -e "puts (-100...100).to_a.shuffle.join(' ')"`
doit:
		./push_swap $$ARG | ./checker_mac $$ARG

clean	:
			/bin/rm -f $(OBJS)

fclean	:	clean
			/bin/rm -f $(NAME)

re		:	fclean	all

