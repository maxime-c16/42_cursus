#include "../includes/push_swap.h"

t_stack	*get_max(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = *stack;
	temp2 = *stack;
	while (temp2 && temp2->next)
	{
		if (temp2->num > temp->num)
			temp = temp2;
		temp2 = temp2->next;
	}
	return (temp);
}

/*void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*max_val;
	int		index;

	index = 1;
	max_val = get_max(stack_a);
	while ((max_val->num / index) > 0)
	{
		counting_sort(stack_a, stack_b);
	}
}*/

void	ft_neg_sorting(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp1;
	t_stack	*temp2;
	int		size;

	temp1 = *stack_a;
	temp2 = *stack_b;
	size = get_size(stack_a);
	while (size)
	{
		if (temp1->num >= 0)
			ft_exec_cmd("RA", &temp1, &temp2);
		else if (temp1->num < 0)
		{
			ft_exec_cmd("PA", &temp1, &temp2);
		}
		size--;
		ft_print_lst(stack_a, stack_b);
	}
	while (temp2->next)
	{
		ft_exec_cmd("PB", &temp1, &temp2);
	}
}
