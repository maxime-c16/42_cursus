#include "../includes/ft_printf.h"

int	ft_is_i(char c)
{
	if (c == 'i')
		return (1);
	else
		return (0);
}

int	ft_is_u(char c)
{
	if (c == 'u')
		return (1);
	else
		return (0);
}

int	ft_is_x(char c)
{
	if (c == 'x')
		return (1);
	else
		return (0);
}

int	ft_is_d(char c)
{
	if (c == 'd')
		return (1);
	else
		return (0);
}
