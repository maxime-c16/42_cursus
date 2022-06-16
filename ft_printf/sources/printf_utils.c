#include "../includes/ft_printf.h"

int	ft_putnbr_pf(int nb)
{
	int				wrdcnt;
	unsigned int	nbr;

	wrdcnt = 0;
	if (nb < 0)
	{
		nbr = -nb;
		ft_putchar('-');
		wrdcnt++;
	}
	else
		nbr = nb;
	if (nbr >= 10)
	{
		wrdcnt += ft_putnbr_pf(nbr / 10);
		wrdcnt += ft_putnbr_pf(nbr % 10);
	}
	else
	{
		ft_putchar(nbr + '0');
		wrdcnt++;
	}
	return (wrdcnt);
}

int	ft_putnbr_db_pf(unsigned int nb)
{
	int		wrdcnt;

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

int	ft_putstr_pf(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr_base_pf(unsigned int nbr)
{
	char			*base;
	unsigned long	nb;
	int				wrdcnt;

	base = "0123456789abcdef";
	nb = nbr;
	wrdcnt = 0;
	if (nb >= 16)
	{
		wrdcnt += ft_putnbr_hex(nb / 16);
		wrdcnt += ft_putnbr_hex(nb % 16);
	}
	else
	{
		ft_putchar(base[nb % 16]);
		wrdcnt++;
	}
	return (wrdcnt);
}

int	ft_putnbr_hex(unsigned long nbr)
{
	char			*base;
	unsigned long	nb;
	int				wrdcnt;

	base = "0123456789abcdef";
	nb = nbr;
	wrdcnt = 0;
	if (nb >= 16)
	{
		wrdcnt += ft_putnbr_hex(nb / 16);
		wrdcnt += ft_putnbr_hex(nb % 16);
	}
	else
	{
		ft_putchar(base[nb % 16]);
		wrdcnt++;
	}
	return (wrdcnt);
}
