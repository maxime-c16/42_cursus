#include "../includes/ft_printf.h"

int	ft_printchar(va_list args)
{
	int		wrdcnt;
	char	c;

	wrdcnt = 0;
	c = (const char)va_arg(args, int);
	ft_putchar(c);
	wrdcnt++;
	return (wrdcnt);
}

int	ft_printstr(va_list args)
{
	int			wrdcnt;
	const char	*temp;

	wrdcnt = 0;
	temp = (const char *)va_arg(args, const char *);
	if (!temp)
	{
		ft_putstr_pf("(null)");
		return (6);
	}
	wrdcnt += ft_putstr_pf(temp);
	return (wrdcnt);
}
