#include "../includes/ft_printf.h"

int     ft_strlen_arg(char *str)
{
    int     i;
    int     res;

    i = 0;
    res = 0;
    while (str[i])
    {
        if (str[i] == '%' && str[i + 1] && ft_is_args(str[i + 1]))
            res++;
        i++;
    }
    return (res);
}

char    *ft_first_parsing(char *str)
{
    int     i;
    int     j;
    int     len;
    char    *arg;

    i = 0;
    j = 0;
    len = ft_strlen_arg(str);
    arg = malloc(sizeof(char) * (len + 1));
    if (!arg)
        return (0);
    while (str[i])
    {
        if (str[i] == '%' && str[i + 1] && ft_is_args(str[i + 1]))
        {
            arg[j] = str[i + 1];
            j++;
        }
        i++;
    }
    return (arg);
}