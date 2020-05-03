/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 22:49:54 by tlee              #+#    #+#             */
/*   Updated: 2020/05/03 03:16:47 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	case_c(t_printf wh, int c)
{
	wh.tmp = ft_strnew(1);
	wh.tmp[0] = c;
	return (wh);
}

t_printf	case_s(t_printf wh, char *s)
{
	int i;
	int length;

	if (s == NULL)
	{
		if (wh.pre == -1)
			wh.pre = 6;
		wh.tmp = ft_strncpy(ft_strnew(wh.pre), "(null)", wh.pre);
	}
	else
	{
		if (wh.star_minus)
			wh.pre = ft_strlen(s);
		if (wh.flag_dot && wh.pre == -1)
			wh.pre = 0;
		length = ft_strlen(s) >= (size_t)wh.pre ? \
								(size_t)wh.pre : ft_strlen(s);
		wh.tmp = ft_strnew(length);
		i = -1;
		while (++i < length)
			wh.tmp[i] = s[i];
	}
	return (wh);
}

t_printf	case_d(t_printf wh, int d)
{
	char	*arr;

	if (wh.pre == 0 && d == 0)
		wh.tmp = ft_strnew(0);
	else
	{
		if (d < 0)
		{
			d = -1 * d;
			wh.sign = 1;
		}
		wh = dtoa(wh, d);
		if (wh.pre != -1 && (int)ft_strlen(wh.tmp) < wh.pre)
		{
			arr = ft_strnew(wh.pre - ft_strlen(wh.tmp));
			arr = ft_memset(arr, '0', wh.pre - ft_strlen(wh.tmp));
			wh.tmp = ft_strjoin(arr, wh.tmp);
		}
	}
	return (wh);
}

t_printf	case_ux(t_printf wh, unsigned int ux)
{
	char	*arr;

	if (wh.pre == 0 && ux == 0)
		wh.tmp = ft_strnew(0);
	else
	{
		wh = wh.con == 'u' || wh.con == 'U' ? utoa(wh, ux) : xtoa(wh, ux);
		if (wh.pre != -1 && (int)ft_strlen(wh.tmp) < wh.pre)
		{
			arr = ft_strnew(wh.pre - ft_strlen(wh.tmp));
			arr = ft_memset(arr, '0', wh.pre - ft_strlen(wh.tmp));
			wh.tmp = ft_strjoin(arr, wh.tmp);
		}
	}
	return (wh);
}

t_printf	case_p(t_printf wh, unsigned long long int p)
{
	char *arr;

	if (wh.pre == 0 && p == 0)
		wh.tmp = ft_strnew(0);
	else
	{
		wh = ptoa(wh, p);
		if (wh.pre != -1 && (int)ft_strlen(wh.tmp) < wh.pre)
		{
			arr = ft_strnew(wh.pre - ft_strlen(wh.tmp));
			arr = ft_memset(arr, '0', wh.pre - ft_strlen(wh.tmp));
			wh.tmp = ft_strjoin(arr, wh.tmp);
		}
	}
	return (wh);
}
