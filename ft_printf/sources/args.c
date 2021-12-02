#include "../includes/ft_printf.h"

int	ft_is_c(char c)
{
	if (c == 'c')
		return (1);
	else
		return (0);
}

int	ft_is_s(char c)
{
	if (c == 's')
		return (1);
	else
		return (0);
}

int	ft_is_p(char c)
{
	if (c == 'p')
		return (1);
	else
		return (0);
}

int	ft_is_args(char c)
{
	if (ft_is_c(c) || ft_is_d(c) || ft_is_i(c) || ft_is_p(c)
		|| ft_is_s(c) || ft_is_u(c) || ft_is_x(c))
		return (1);
	else
		return (0);
}
