#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
	return ;
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = '0';
	while (a <= '9')
	{
		b = '0';
		while (b <= '9')
		{
			c = '0';
			while (c <= '9')
			{
				d = b + 1;
				while (d <= '9')
				{
					if (a != c || b != d)
					{
						ft_putchar(a);
						ft_putchar(b);
						ft_putchar(' ');
						ft_putchar(c);
						ft_putchar(d);
						if (a != '9'|| b != '8' || c != '9' || d != '9')
						{
							ft_putchar(',');
							ft_putchar(' ');
						}
						if (a == '9' && b == '8' && c == '9' && d == '9')
							return ; 
					}	
					d++;
				}
				c++;
			}
			b++;
		}
		a++;
	}
}
