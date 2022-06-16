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
		return (ft_putunsigned(args));
	else if (str[index] == 'X')
		return (ft_X(args));
	else if (str[index] == '%')
	{
		ft_putchar('%');
		return (1);
	}
	return (0);
}

int	ft_putnbr_base_X(unsigned int nbr)
{
	char			*base;
	unsigned long	nb;
	int				wrdcnt;

	base = "0123456789ABCDEF";
	nb = nbr;
	wrdcnt = 0;
	if (nb >= 16)
	{
		wrdcnt += ft_putnbr_base_X(nb / 16);
		wrdcnt += ft_putnbr_base_X(nb % 16);
	}
	else
	{
		ft_putchar(base[nb % 16]);
		wrdcnt++;
	}
	return (wrdcnt);
}
