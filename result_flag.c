#include "ft_printf.h"

t_printf    result_flag_p(t_printf f)
{
    char    *temp;

    if (!f.flag_minus && f.size_res <= f.size_val)
    {
        temp = ft_strnew(2);
        temp[0] = '0';
        temp[1] = 'x';
        f.res = ft_strjoin(temp, f.res);
    }
    else if (!f.flag_minus && f.size_res == f.size_val + 1)
    {
        temp = ft_strnew(1);
        temp[0] = '0';
        f.res[0] = 'x';
        f.res = ft_strjoin(temp, f.res);
    }
    else
    {
        f.loc = 0;
        while (!f.flag_zero && f.res[f.loc] == ' ')
            f.loc++;
        f.res[f.flag_zero ? 0 : f.loc - 2] = '0';
        f.res[f.flag_zero ? 1 : f.loc - 1] = 'x';
    }
    return (f);
}

char        result_flag_set_sign(t_printf f)
{
    if (f.sign)
        return ('-');
    else
        return (' ');
}

t_printf    result_flag_sign(t_printf f)
{
    char    *temp;

    if (!f.flag_minus && f.size_val >= f.size_res)
    {
        temp = ft_strnew(1);
        if (f.sign)
            temp[0] = '-';
        f.res = ft_strjoin(temp, f.res);
    }
    else
    {
        f.loc = 0;
        while (f.res[f.loc] == ' ')
            f.loc++;
        if ((f.flag_zero && f.wid > f.size_val && !f.loc) || (!f.pre && f.flag_minus))
            f.res[0] = result_flag_set_sign(f);
        else
            f.res[f.loc - 1] = result_flag_set_sign(f);
    }
    return (f);
}
