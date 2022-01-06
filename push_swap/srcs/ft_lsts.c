#include "../includes/push_swap.h"

void	ft_init_lst(t_stack **stack, int nb)
{
	*stack = (t_stack *)malloc(sizeof(*stack));
	if (*stack == NULL)
		ft_exit("Malloc error\n", 1);
	(*stack)->num = nb;
	(*stack)->next = NULL;
	(*stack)->prev = NULL;
	return ;
}

t_stack	*ft_lstnew(int num)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(*new));
	if (new == NULL)
		ft_exit("Malloc error", 1);
	new->num = num;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	while (lst)
	{
		if (!(lst->next))
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_stack **stack, int nb)
{
	t_stack	*tmp;
	t_stack	*cpy;

	tmp = ft_lstnew(nb);
	cpy = *stack;
	if (cpy == NULL)
		ft_exit("stack is empty\n", 1);
	while (cpy->next)
		cpy = cpy->next;
	cpy->next = tmp;
	tmp->prev = cpy;
	printf("int push sur stack: %d\n", cpy->next->num);
}

void	ft_lstadd_back_r(t_stack **stack)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp1 = NULL;
	temp1 = *stack;
	temp2 = (*stack)->prev;
	while (temp1->next)
		temp1 = temp1->next;
	temp1->next = temp2;
	temp1->next->prev = temp1;
	temp1->next->next = NULL;
	write(1, "test\n", 6);
	return ;
}
