#include "../includes/push_swap.h"

t_stack	*get_max(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = *stack;
	temp2 = *stack;
	while (temp2 && temp2->next)
	{
		if (temp2->index > temp->index)
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
			if (((temp1->index >> i) & 1) == 1)
				ft_exec_cmd("ra", stack_a, stack_b);
			else
				ft_exec_cmd("pb", stack_a, stack_b);
			++j;
		}
		ft_putback_in_stck(stack_a, stack_b);
		++i;
	}
	while ((*stack_a)->index != get_minimum(stack_a))
		ft_exec_cmd("ra", stack_a, stack_b);
}

char	**ft_cpy_num(char **cpy, t_stack **stack, int size)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *stack;
	cpy = (char **)malloc(sizeof(char *) * (size + 1));
	while (temp && temp->next)
	{
		cpy[i] = ft_itoa(temp->num);
		printf("%s\n", *cpy);
		temp = temp->next;
		i++;
	}
	return (cpy);
}

void	ft_normalize(t_stack **stack)
{
	int		i;
	int		j;
	int		size;
	char	**cpy;
	t_stack	*temp;

	i = 0;
	temp = *stack;
	size = get_size(&temp);
	cpy = ft_cpy_num(cpy, &temp, size);
	quicksort(cpy, 0, size - 1);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (ft_atoi(cpy[i]) == (temp + j)->num)
				(temp + j)->index = i;
			j++;
			//printf("i = %d, j = %d", i, j);
		}
		i++;
	}
	return ;
}
