/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 23:44:38 by tlee              #+#    #+#             */
/*   Updated: 2020/05/03 18:25:30 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	result_put(t_printf wh)
{
	int	i;
	int	j;

	if (wh.flag_minus)
	{
		i = wh.sign;
		if (wh.con == 'p')
			i = i + 2;
		j = 0;
		while (wh.tmp[j])
			wh.res[i++] = wh.tmp[j++];
	}
	else
	{
		i = wh.size_res - 1;
		j = wh.size_tmp - 1;
		while (j >= 0)
			wh.res[i--] = wh.tmp[j--];
	}
	return (wh);
}

t_printf	result_set(t_printf wh)
{
	int	len;

	len = 0;
	wh.size_tmp = ft_strlen(wh.tmp);
	if (len < wh.size_tmp)
		len = wh.size_tmp;
	if (len < wh.wid)
		len = wh.wid;
	wh.res = ft_strnew(len);
	if (wh.flag_zero && !wh.flag_minus && (wh.pre == -1 || wh.star_minus))
		wh.res = ft_memset(wh.res, '0', len);
	else
		wh.res = ft_memset(wh.res, ' ', len);
	wh.size_res = ft_strlen(wh.res);
	return (wh);
}

t_printf	result(t_printf wh)
{
	wh = result_set(wh);
	wh = result_put(wh);
	if (wh.con != 'u' && wh.con != '%' && wh.sign)
		wh = result_apply_sign(wh);
	if (wh.con == 'p')
		wh = result_apply_p(wh);
	return (wh);
}
