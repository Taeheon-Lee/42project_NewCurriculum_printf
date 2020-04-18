#include "ft_printf.h"

t_printf    dtoa(t_printf f, long long int d)
{
    size_t i;

    if (d - 1 == 9223372036854775807)
    {
        f.val = ft_strnew(20);
        f.val = ft_strcpy(f.val, "-9223372036854775808");
        f.sign = 0;
        return (f);
    }
    i = ft_count_digit(d);
    f.val = ft_strnew(i--);
    f.val[i--] = d % 10 +'0';
    while ((d = d / 10))
        f.val[i--] = d % 10 + '0';
    return (f);
}

t_printf    utoa(t_printf f, unsigned long long int u)
{
    size_t i;

    i = ft_count_digit(u);
    f.val = ft_strnew(i--);
    f.val[i--] = u % 10 + '0';
    while ((u = u / 10))
        f.val[i--] = u % 10 + '0';
    return (f);
}

t_printf    xtoa(t_printf f, unsigned long long int x)
{
    int                     i;
    unsigned long long int  j;

    if (x == 0)
    {
        f.val = ft_strnew(1);
        f.val[0] = '0';
        return (f);
    }
    i = 0;
    j = x;
    while ((j = j / 16))
        i++;
    f.val = ft_strnew(i + 1);
    while (x != 0)
    {
        if ((j = x % 16) >= 10)
            f.val[i] = (f.con == 'X' ? 'A' : 'a') + j - 10;
        else
            f.val[i] = j + '0';
        x = x / 16;
        i--;
    }
    return (f);
}
