#include "ft_printf.h"

t_printf    result_put(t_printf f)
{
    int i_res;
    int i_val;

    if (f.flag_minus)
    {
        i_res = f.sign;
        if (ft_strcmp(f.val, "0") && \
        (f.con == 'x' || f.con == 'X' || f.con == 'o' || f.con == 'O'))
            i_res = i_res + (f.con == 'x' || f.con == 'X' ? 2 : 1);
        if (f.con == 'p')
            i_res = i_res + 2;
        i_val = 0;
        while (f.val[i_val])
            f.res[i_res++] = f.val[i_val++];
    }
    else
    {
        i_res = f.size_res - 1;
        i_val = f.size_val - 1;
        while (i_val >= 0)
            f.res[i_res--] = f.val[i_val--];
    }
    return (f);
}

t_printf    result_set(t_printf f)
{
    int len;

    len = 0;
    f.size_val = ft_strlen(f.val);
    if (len < f.size_val)
        len = f.size_val;
    if (len < f.wid)
        len = f.wid;
    f.res = ft_strnew(len);
    if (f.flag_zero && !f.flag_minus && f.pre == -1)
        f.res = ft_memset(f.res, '0', len);
    else
        f.res = ft_memset(f.res, ' ', len);
    f.size_res = ft_strlen(f.res);
    return (f);
}

t_printf    result(t_printf f)
{
    f = result_set(f);
    f = result_put(f);
    if (f.con != 'u' && f.con != '%' && f.sign)
        f = result_flag_sign(f);
    if (f.con == 'p')
        f = result_flag_p(f);
    return (f);
}
