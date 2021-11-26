#include "includes/ft_printf.h"

int     ft_printf(char const *str, ...)
{
    int     i;
    int     wrdcnt;
    va_list args;

    i = 0;
    wrdcnt = 0;
    va_start(args, str);
    while (str[i])
    {
        if (str[i] == '%' && str[i + 1] && ft_is_args(str[i + 1]))
        {
            wrdcnt += ft_putarg((char *)str, i + 1, args);
            i += 2;
        }
        if (str[i] && str[i] != '%')
        {
            ft_putchar(str[i]);
            i++;
            wrdcnt++;
        }
    }
    return (wrdcnt);
}

int main()
{
    int res;

    res = ft_printf("maxime %s %c %d \ncauchy", "tst str", 'a', 10);
    ft_printf("\nres = %d", res);
    return (0);
}
