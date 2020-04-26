/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 20:41:27 by tlee              #+#    #+#             */
/*   Updated: 2020/04/26 23:54:52 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	check(char **format, t_printf wh, va_list ap)
{
	while ((*format)[wh.loc])
	{
		if ((wh.con = set_con((*format)[wh.loc])) != 0)
			return (wh) ;
		else if (check_flag((*format)[wh.loc]))
			wh = set_flag(wh, (*format)[wh.loc]);
		else if (check_num((*format)[wh.loc]))
			wh = set_wid(wh, (*format));
		else if (check_star((*format)[wh.loc]))
			wh = set_star(wh, format, va_arg(ap, int));
		else if (check_dot((*format)[wh.loc]))
		{
			wh.loc++;
			if (check_star((*format)[wh.loc]))
				wh = set_star(wh, format, va_arg(ap, int));
			else
				wh = set_pre(wh, (*format));
		}
		if (wh.err)
			break ;
		wh.loc++;
	}
	wh.err = 1;
	return (wh);
}

int		check_flag(char c)
{
	if (c == '-' || c == '0')
		return (1);
	return (0);
}

int		check_num(char c)
{
	if (c >= '1' && c <= '9')
		return (1);
	return (0);
}

int		check_dot(char c)
{
	if (c == '.')
		return (1);
	return (0);
}

int		check_star(char c)
{
	if (c == '*')
		return (1);
	return (0);
}
