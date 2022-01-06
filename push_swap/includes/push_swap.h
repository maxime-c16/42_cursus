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
void	push_swap(int ac, char **av);

typedef struct s_list
{
	int				num;
	struct s_list	*prev;
	struct s_list	*next;
}					t_stack;

t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int num);
void	ft_lstadd_back(t_stack **stack, int nb);
void	ft_lstadd_front(t_stack **stack, t_stack *elem);
void	ft_init_lst(t_stack **stack, long nb);
void	ft_print_lst(t_stack **stack_a, t_stack **stack_b);

//parsing function

void	ft_check_int(long nb);
void	ft_parse_case(t_stack **stack, char *str);
char	**ft_split(char *s, char c);

//rotate functions

void	ft_back_r(t_stack **stack);
void	ft_rotate_stck(t_stack **stack);

//push functions

void	ft_push_stck(t_stack **stack_a, t_stack **stack_b);
void	ft_del_one(t_stack **stack);

#endif
