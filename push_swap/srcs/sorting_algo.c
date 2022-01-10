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

int	get_max_bits(int nb)
{
	int	i;

	i = 0;
	while (nb >> i)
		i++;
	return (i);
}

void	ft_putback_in_stck(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
		ft_exec_cmd("pa", stack_a, stack_b);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, \
					t_stack *temp1, t_stack *temp2)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	temp1 = NULL;
	size = get_size(stack_a);
	max_bits = get_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size + 1)
		{
			temp1 = *stack_a;
			if (((temp1->num >> i) & 1) == 1)
				ft_exec_cmd("ra", stack_a, stack_b);
			else
				ft_exec_cmd("pb", stack_a, stack_b);
			++j;
		}
		ft_putback_in_stck(stack_a, stack_b);
		++i;
	}
	while ((*stack_a)->num != get_minimum(stack_a))
		ft_exec_cmd("ra", stack_a, stack_b);
}

void	ft_smart_rotate(t_stack **stack_a, t_stack **stack_b)
{
	
}
