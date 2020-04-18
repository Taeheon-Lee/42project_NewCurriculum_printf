#include "ft_printf.h"

int exit_percent(const char *format, int i)
{
    int over;

    over = 0;
    while (set_con(format[i + over]) == 0)
        over++;
    return (i + 1 + over);
}

int percent_print(t_printf f)
{
    int result;

    if (f.con == 'c' && !ft_strcmp(f.val, ""))
    {
        f.loc = 0;
        if (f.flag_minus)
        {
            ft_putchar(0);
            while (f.loc++ < f.wid - 1)
                ft_putchar(' ');
        }
        else
        {
            while (f.loc++ < f.wid - 1)
                ft_putchar(' ');
            ft_putchar(0);
        }
        return(f.loc);
    }
    result = ft_strlen(f.res);
    ft_putstr(f.res);
    free(f.res);
    free(f.val);
    return (result);
}

int percent_pass(t_printf f, va_list ap)
{
    if (f.con == 'c' || f.con == 'C')
        f = case_c(f, va_arg(ap, int));
    if (f.con == 's' || f.con == 'S')
        f = case_s(f, va_arg(ap, char *));
    if (f.con == 'd' || f.con == 'D' || f.con == 'i')
        f = case_d(f, va_arg(ap, long long int));
    if (f.con == 'u' || f.con == 'U')
        f = case_u(f, va_arg(ap, unsigned long long int));
    if (f.con == 'x' || f.con == 'X' || f.con == 'p')
        f = case_x(f, va_arg(ap, unsigned long long int));
    if (f.con == '%')
        f = case_c(f, '%');
    f = result(f);
    return (percent_print(f));
}

int percent_start(const char *format, int i, va_list ap)
{
    t_printf    f;

    ft_memset(&f, 0, sizeof(f));
    f.loc = i;
    f.pre = -1;
    while (format[f.loc])
    {
        if ((f.con = set_con(format[f.loc])) != 0)
            break ;
        if (Check_flag(format[f.loc]))
            f = set_flag(f, format[f.loc]);
        if (Check_num(format[f.loc]))
            f = set_wid(f, format);
        if (Check_dot(format[f.loc]))
            f = set_pre(f, format);
        f.loc++;
    }
    if (f.con == 0)
        return (-1);
    return (percent_pass(f, ap));
}

int percent(const char *format, va_list ap)
{
    int i;
    int result;
    int temp;

    i = 0;
    result = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            temp = percent_start(format, i + 1, ap);
            if (temp == -1)
                break ;
            result = result + temp;
            i = exit_percent(format, i + 1);
        }
        else
        {
            ft_putchar(format[i]);
            result++;
            i++;
        }
    }
    return (result);
}
