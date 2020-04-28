/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casetoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 23:19:24 by tlee              #+#    #+#             */
/*   Updated: 2020/04/28 17:54:52 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	dtoa(t_printf wh, int d)
{
	int	i;

	if (d - 1 == 2147483647)
	{
		wh.tmp = ft_strnew(11);
		wh.tmp = ft_strcpy(wh.tmp, "-2147483648");
		wh.sign = 0;
		return (wh);
	}
	i = ft_count_digit(d);
	wh.tmp = ft_strnew(i--);
	wh.tmp[i--] = d % 10 + '0';
	while ((d = d / 10))
		wh.tmp[i--] = d % 10 + '0';
	return (wh);
}

t_printf	utoa(t_printf wh, unsigned int u)
{
	int	i;

	if (u == 0)
	{
		wh.tmp = ft_strnew(1);
		wh.tmp[0] = '0';
		return (wh);
	}
	i = ft_count_digit(u);
	wh.tmp = ft_strnew(i--);
	wh.tmp[i--] = u % 10 + '0';
	while ((u = u / 10))
		wh.tmp[i--] = u % 10 + '0';
	return (wh);
}

t_printf	xtoa(t_printf wh, unsigned int x)
{
	int				i;
	unsigned int	j;

	if (x == 0)
	{
		if (wh.pre == -1 || wh.pre == 0)
			wh.tmp = ft_strnew(0);
		else
			wh.tmp = ft_strcpy(ft_strnew(1), "0");
		return (wh);
	}
	i = 0;
	j = x;
	while ((j = j / 16))
		i++;
	wh.tmp = ft_strnew(i + 1);
	while (x != 0)
	{
		if ((j = x % 16) >= 10)
			wh.tmp[i] = (wh.con == 'X' ? 'A' : 'a') + j - 10;
		else
			wh.tmp[i] = j + '0';
		x = x / 16;
		i--;
	}
	return (wh);
}
