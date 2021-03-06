/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 20:41:27 by tlee              #+#    #+#             */
/*   Updated: 2020/05/03 18:16:54 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	check(const char *format, t_printf wh, va_list ap)
{
	while (format[++wh.loc])
	{
		if (format[wh.loc - 1] == '.' && format[wh.loc] != '*')
		{
			wh = set_pre(wh, format);
			if (wh.con)
				break ;
			continue ;
		}
		if ((wh.con = set_con(format[wh.loc])) != 0)
			break ;
		else if (check_flag(format[wh.loc]))
			wh = set_flag(wh, format[wh.loc]);
		else if (check_num_wid(format[wh.loc]))
			wh = set_wid(wh, format);
		else if (format[wh.loc] == '*')
			wh = set_star(wh, format, va_arg(ap, int));
		else if (format[wh.loc] == '.')
			wh.flag_dot = 1;
	}
	if (!wh.con)
		wh.err = 1;
	return (wh);
}

int			check_flag(char c)
{
	if (c == '-' || c == '0')
		return (1);
	return (0);
}

int			check_num_wid(char c)
{
	if (c >= '1' && c <= '9')
		return (1);
	return (0);
}
