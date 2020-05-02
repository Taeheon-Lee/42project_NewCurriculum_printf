/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 16:36:06 by tlee              #+#    #+#             */
/*   Updated: 2020/05/03 00:53:18 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	exit_percent(const char *format, int i)
{
	int		cnt;
	char	c;

	cnt = 0;
	while (1)
	{
		c = format[i + cnt];
		if (set_con(c))
			break ;
		cnt++;
	}
	return (i + cnt + 1);
}

int	percent_print(t_printf wh)
{
	int	result;

	if (wh.con == 'c' && !ft_strcmp(wh.tmp, ""))
	{
		wh.loc = 0;
		if (wh.flag_minus)
		{
			ft_putchar(0);
			while (wh.loc++ < wh.wid - 1)
				ft_putchar(' ');
		}
		else
		{
			while (wh.loc++ < wh.wid - 1)
				ft_putchar(' ');
			ft_putchar(0);
		}
		return (wh.loc);
	}
	result = ft_strlen(wh.res);
	ft_putstr(wh.res);
	free(wh.res);
	free(wh.tmp);
	return (result);
}

int	percent_pass(t_printf wh, va_list ap)
{
	if (wh.con == 'c' || wh.con == 'C')
		wh = case_c(wh, va_arg(ap, int));
	else if (wh.con == 's' || wh.con == 'S')
		wh = case_s(wh, va_arg(ap, char *));
	else if (wh.con == 'd' || wh.con == 'D' || wh.con == 'i')
		wh = case_d(wh, va_arg(ap, int));
	else if (wh.con == 'u' || wh.con == 'U' || wh.con == 'x' || wh.con == 'X')
		wh = case_ux(wh, va_arg(ap, unsigned int));
	else if (wh.con == 'p')
		wh = case_p(wh, va_arg(ap, unsigned long long int));
	else if (wh.con == '%')
		wh = case_c(wh, '%');
	wh = result(wh);
	return (percent_print(wh));
}

int	percent_start(const char *format, int tmp_loc, va_list ap)
{
	t_printf wh;

	ft_memset(&wh, 0, sizeof(wh));
	wh.loc = tmp_loc;
	wh.pre = -1;
	wh = check(format, wh, ap);
	if (wh.err == 1)
		return (-1);
	return (percent_pass(wh, ap));
}

int	percent(const char *format, va_list ap)
{
	int i;
	int result;
	int tmp;

	if (!ft_strcmp(format, "%"))
		return (0);
	i = 0;
	result = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if ((tmp = percent_start(format, i, ap)) != -1)
			{
				result = result + tmp;
				i = exit_percent(format, i + 1);
				continue ;
			}
		}
		ft_putchar(format[i]);
		result++;
		i++;
	}
	return (result);
}
