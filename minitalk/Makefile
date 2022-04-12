CLT_SRC	=	client.c

SRV_SRC	=	serveur.c

CLT_OBJ	=	$(CLT_SRC:.c=.o)

SRV_OBJ	=	$(SRV_SRC:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

SRV		=	serveur

CLT		=	client

all		:	$(SRV) $(CLT)

$(SRV)	:	$(SRV_OBJ)
			$(CC)  -o $@ $^

$(CLT)	:	$(CLT_OBJ)
			$(CC)  -o $@ $^

clean	:
			/bin/rm -f $(SRV_OBJ)
			/bin/rm -f $(CLT_OBJ)

fclean	:	clean
			/bin/rm -f $(SRV)
			/bin/rm -f $(CLT)

re		:	fclean all
