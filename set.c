#include "ft_printf.h"

t_printf    set_pre(t_printf f, const char *s)
{
    int result;

    result = 0;
    f.loc++;
    while (s[f.loc] >= '0' && s[f.loc] <= '9')
    {
        result = result * 10 + s[f.loc] - '0';
        f.loc++;
    }
    f.pre = result;
    f.loc--;
    return (f);
}

t_printf    set_wid(t_printf f, const char *s)
{
    int result;

    result = 0;
    if (s[f.loc - 1] != 0 && s[f.loc - 1] == '.')
        return (f);
    while (s[f.loc] >= '0' && s[f.loc] <= '9')
    {
        result = result * 10 + s[f.loc] - '0';
        f.loc++;
    }
    f.wid = result;
    f.loc--;
    return (f);
}

t_printf    set_flag(t_printf f, char c)
{
    if (c == '-')
        f.flag_minus = 1;
    if (c == '0')
        f.flag_zero = 1;
    return (f);
}

char        set_con(char c)
{
    if (c == 'd' || c == 'D' || c == 'i' || c == 'u' || c == 'U' ||
    c == 'x' || c == 'X' || c == 'p' || c == 'o' || c == 'O' ||
    c == 'f' || c == 'F' || c == 'c' || c == 'C' || c == '%' ||
    c == 'Z' || c == 's' || c == 'S')
        return (c);
    return (0);
}
