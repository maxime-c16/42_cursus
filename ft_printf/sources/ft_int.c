#include "../includes/ft_printf.h"

int	ft_printptr(va_list args)
{
	int				wrdcnt;
	unsigned long	ptr;

	wrdcnt = 0;
	ptr = (unsigned long)va_arg(args, unsigned long);
	ft_printf("0x");
	wrdcnt += ft_putnbr_hex(ptr);
	return (wrdcnt + 2);
}

int	ft_putint(va_list args)
{
	int		wrdcnt;
	int		dval;

	wrdcnt = 0;
	dval = (int)va_arg(args, int);
	wrdcnt += ft_putnbr_pf(dval);
	return (wrdcnt);
}

int	ft_puthex(va_list args)
{
	int				wrdcnt;
	unsigned int	hexval;

	wrdcnt = 0;
	hexval = (int)va_arg(args, int);
	wrdcnt += ft_putnbr_base_pf(hexval);
	return (wrdcnt);
}

int	ft_putunsigned(va_list args)
{
	int				wrdcnt;
	unsigned int	uval;

	wrdcnt = 0;
	uval = (unsigned int)va_arg(args, unsigned int);
	wrdcnt += ft_putnbr_db_pf(uval);
	return (wrdcnt);
}

int	ft_X(va_list args)
{
	int				wrdcnt;
	unsigned int	hexval;

	wrdcnt = 0;
	hexval = (int)va_arg(args, int);
	wrdcnt += ft_putnbr_base_X(hexval);
	return (wrdcnt);
}
