#include "../includes/ft_printf.h"

int	ft_putnbr_pf(int nb)
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

int	ft_putnbr_base_pf(int nbr, char *base)
{
	int		size_base;
	int		nbr_final[100];
	int		i;
	int		wrdcnt;

	i = 0;
	size_base = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
	}
	while (base[size_base])
		size_base++;
	while (nbr)
	{
		nbr_final[i] = nbr % size_base;
		nbr = nbr / size_base;
		i++;
	}
	wrdcnt = i;
	while (--i >= 0)
		ft_putchar(base[nbr_final[i]]);
	return (wrdcnt);
}

int	ft_putnbr_hex(unsigned int nbr, char *base)
{
	int		size_base;
	int		nbr_final[100];
	int		i;
	int		wrdcnt;

	i = 0;
	size_base = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
	}
	while (base[size_base])
		size_base++;
	while (nbr)
	{
		nbr_final[i] = nbr % size_base;
		nbr = nbr / size_base;
		i++;
	}
	wrdcnt = i;
	while (--i >= 0)
		ft_putchar(base[nbr_final[i]]);
	return (wrdcnt);
}
