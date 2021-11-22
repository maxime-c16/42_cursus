#include "../includes/ft_printf.h"

int    ft_putarg(char *str, int index, va_list args)
{
    int             dval;
    double          dblvalue;
    char            cvalue;
    const char      *strvalue;
    void            *pvalue;
    unsigned int    uvalue;
    int             wrdcnt;

    wrdcnt = 0;
    if (str[index] == 'd')
    {
        dval = (int)va_arg(args, int);
        wrdcnt += ft_putnbr_pf(dval);
        return (wrdcnt);
    }
    else if (str[index] == 'c')
    {
        cvalue = (char)va_arg(args, int);
        ft_putchar(cvalue);
        wrdcnt++;
        return (wrdcnt);
    }
    else if (str[index] == 's')
    {
        strvalue = (const char *)va_arg(args, const char *);
        wrdcnt += ft_putstr_pf((char *)strvalue);
        return (wrdcnt);
    }
    return (wrdcnt);
}