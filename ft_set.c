/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 22:48:40 by tlee              #+#    #+#             */
/*   Updated: 2020/04/22 22:48:43 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	set_pre(t_printf wh, const char *s)
{
	int result;

	result = 0;
	wh.loc++;
	while (s[wh.loc] >= '0' && s[wh.loc] <= '9')
	{
		result = result * 10 + (s[wh.loc] - '0');
		wh.loc++;
	}
	wh.pre = result;
	wh.loc--;
	return (wh);
}

t_printf	set_wid(t_printf wh, const char *s)
{
	int result;

	result = 0;
	if (s[wh.loc - 1] == '.')
		return (wh);
	while (s[wh.loc] >= '0' && s[wh.loc] <= '9')
	{
		result = result * 10 + (s[wh.loc] - '0');
		wh.loc++;
	}
	wh.wid = result;
	wh.loc--;
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
	if (c == 'c' || c == 'C' || c == 's' || c == 'S' || c == 'd' \
			|| c == 'D' || c == 'i' || c == 'u' || c == 'U' \
			|| c == 'x' || c == 'X' || c == 'p' || c == '%')
		return (c);
	return (0);
}
