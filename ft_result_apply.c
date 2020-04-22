/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_apply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 00:04:44 by tlee              #+#    #+#             */
/*   Updated: 2020/04/23 00:57:20 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	result_apply_p(t_printf wh)
{
	char	*arr;

	if (!wh.flag_minus && (wh.size_res == wh.size_tmp + 1))
	{
		arr = ft_strnew(1);
		arr[0] = '0';
		wh.res[0] = 'x';
		wh.res = ft_strjoin(arr, wh.res);
	}
	else if (!wh.flag_minus && (wh.size_res <= wh.size_tmp))
	{
		arr = ft_strnew(2);
		arr[0] = '0';
		arr[1] = 'x';
		wh.res = ft_strjoin(arr, wh.res);
	}
	else
	{
		wh.loc = 0;
		while (!wh.flag_zero && wh.res[wh.loc] == ' ')
			wh.loc++;
		wh.res[wh.flag_zero ? 0 : wh.loc - 2] = '0';
		wh.res[wh.flag_zero ? 1 : wh.loc - 1] = 'x';
	}
	return (wh);
}

char		result_put_sign(t_printf wh)
{
	if (wh.sign)
		return ('-');
	else
		return (' ');
}

t_printf	result_apply_sign(t_printf wh)
{
	char	*arr;

	if (!wh.flag_minus && (wh.size_tmp >= wh.size_res))
	{
		arr = ft_strnew(1);
		if (wh.sign)
			arr[0] = '-';
		wh.res = ft_strjoin(arr, wh.res);
	}
	else
	{
		wh.loc = 0;
		while (wh.res[wh.loc] == ' ')
			wh.loc++;
		if ((wh.flag_zero && wh.wid > wh.size_tmp && !wh.loc) || \
				(!wh.pre && wh.flag_minus))
			wh.res[0] = result_put_sign(wh);
		else
			wh.res[wh.loc - 1] = result_put_sign(wh);
	}
	return (wh);
}
