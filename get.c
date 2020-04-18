#include "ft_printf.h"

char    *get_front(t_printf f, long double i)
{
    char            *result;
    long long int   t;

    f.loc = 0;
    while (f.pre != -1 && f.loc < f.pre + 1)
    {
        i = i * 10;
        f.loc++;
    }
    if ((long long int)i % 10  >= 5)
        i = i + 10;
    f.loc = 0;
    while (f.pre != -1 && f.loc < f.pre + 1)
    {
        i = i / 10;
        f.loc++;
    }
    t = i;
    result = dtoa(f, t).val;
    return (result);
}

char    *get_back(t_printf f, long double i)
{
    char            *result;

    f.loc = 0;
    while (f.pre != -1 && f.loc < f.pre + 1)
    {
        i = i * 10;
        f.loc++;
    }
    if ((long long int)i % 10  >= 5)
	i = i + 10;
    result = ft_strnew(f.pre);
    f.loc = f.pre - 1;
    i = i / 10;
    while (f.pre != -1 && f.loc >= 0)
    {
        result[f.loc] = (long long int)i % 10 + '0';
        i = i / 10;
        f.loc--;
    }
    return (result);
}
