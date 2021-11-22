#include "../includes/ft_printf.h"

int     ft_putnbr_pf(int nb)
{
    int wrdcnt;

    wrdcnt = 0;
	if (nb < 0)
	{
		nb = -nb;
        wrdcnt++;
	}
	if (nb >= 10)
	{
		wrdcnt += ft_putnbr_pf(nb / 10);
		wrdcnt += ft_putnbr_pf(nb % 10);
	}
	else
    {
		ft_putchar(nb + '0');
        wrdcnt++;
    }
    return (wrdcnt);
}

int     ft_putstr_pf(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
    return (i);
}