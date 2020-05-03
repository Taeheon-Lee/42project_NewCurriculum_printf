/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 22:48:40 by tlee              #+#    #+#             */
/*   Updated: 2020/05/03 20:43:04 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	set_pre(t_printf wh, const char *s)
{
	int result;

	if (s[wh.loc] >= '0' && s[wh.loc] <= '9')
	{
		result = 0;
		while (s[wh.loc] >= '0' && s[wh.loc] <= '9')
		{
			result = result * 10 + (s[wh.loc] - '0');
			wh.loc++;
		}
		wh.loc--;
		wh.pre = result;
	}
	else
		wh.con = set_con(s[wh.loc]);
	if (s[wh.loc] == '-')
		wh.loc--;
	return (wh);
}

t_printf	set_wid(t_printf wh, const char *s)
{
	int result;

	result = 0;
	while (s[wh.loc] >= '0' && s[wh.loc] <= '9')
	{
		result = result * 10 + (s[wh.loc] - '0');
		wh.loc++;
	}
	wh.wid = result;
	wh.loc--;
	return (wh);
}

t_printf	set_star(t_printf wh, const char *format, int d)
{
	if (format[wh.loc - 1] == '.')
	{
		if (d < 0)
		{
			wh.star_minus = 1;
			d = 0;
		}
		wh.pre = d;
	}
	else
	{
		if (d < 0)
		{
			wh.flag_minus = 1;
			d = -1 * d;
		}
		wh.wid = d;
	}
	return (wh);
}

t_printf	set_flag(t_printf wh, char c)
{
	if (c == '-')
		wh.flag_minus = 1;
	else if (c == '0')
		wh.flag_zero = 1;
	return (wh);
}

char		set_con(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u' \
	|| c == 'x' || c == 'X' || c == 'p' || c == '%')
		return (c);
	return (0);
}
