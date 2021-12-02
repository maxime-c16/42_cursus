#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *str, ...);
char	*ft_first_parsing(char *str);
int		ft_strlen_arg(char *str);
int		ft_putnbr_base_pf(unsigned int nb, char *base);
int		ft_putnbr_hex(unsigned int nbr, char *base);
int		ft_putnbr_pf(int nb);
int		ft_putstr_pf(const char *str);
int		ft_puthex(va_list args);
int		ft_putint(va_list args);
int		ft_printstr(va_list args);
int		ft_printchar(va_list args);
int		ft_printptr(va_list args);
int		ft_is_args(char c);
int		ft_is_x(char c);
int		ft_is_u(char c);
int		ft_is_i(char c);
int		ft_is_d(char c);
int		ft_is_p(char c);
int		ft_is_s(char c);
int		ft_is_c(char c);
int		ft_putarg(char *str, int index, va_list args);

#endif
