#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdio.h>

long	ft_atoi(const char *str);
void	ft_exit(char *exit_msg, int exit_code);
int		ft_isdigit(int c);

typedef struct s_list
{
	int				num;
	struct	s_list	*prev;
	struct	s_list	*next;
}					t_stack;


void	ft_lstadd_back_r(t_stack **stack);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int num);
void	ft_lstadd_back(t_stack **stack, int nb);
void	ft_init_lst(t_stack **stack, int nb);
void	ft_print_lst(t_stack **stack);

//rotate function

void	ft_back_r(t_stack **stack);
void	ft_rotate_stck(t_stack **stack);

#endif
