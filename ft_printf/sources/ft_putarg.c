#include "../includes/ft_printf.h"

int	ft_putarg(char *str, int index, va_list args)
{
	if (str[index] == 'd' || str[index] == 'i')
		return (ft_putint(args));
	else if (str[index] == 'x')
		return (ft_puthex(args));
	else if (str[index] == 'c')
		return (ft_printchar(args));
	else if (str[index] == 's')
		return (ft_printstr(args));
	else if (str[index] == 'p')
		return (ft_printptr(args));
	else if (str[index] == 'u')
		return (ft_putunsigend(args));
	return (0);
}
