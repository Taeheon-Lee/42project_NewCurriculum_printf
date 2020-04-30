/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star_apply.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 19:51:34 by tlee              #+#    #+#             */
/*   Updated: 2020/04/30 14:01:34 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	set_star(t_printf wh, char **s, int d)
{
	char	*front;
	char	*star_arr;
	char	*end;

	if ((*s)[wh.loc + 1] >= '0' && (*s)[wh.loc + 1] <= '9')
		wh.err = 1;
	if (d <= 0)
	{
		front = set_star_front(wh, s);
		end = set_star_end(wh, s);
		*s = ft_strjoin(front, end);
		if (d < 0)
			wh.star_minus = 1;
		wh.loc--;
		return (wh);
	}
	front = set_star_front(wh, s);
	star_arr = set_star_arr(d);
	end = set_star_end(wh, s);
	*s = ft_strjoin(front, ft_strjoin(star_arr, end));
	wh.loc--;
	return (wh);
}

char		*set_star_front(t_printf wh, char **s)
{
	char	*arr;
	int		i;

	i = -1;
	arr = ft_strnew(wh.loc);
	while (++i < wh.loc)
		arr[i] = (*s)[i];
	return (arr);
}

char		*set_star_arr(int long long d)
{
	char	*arr;
	int		cnt;
	int		sign;

	sign = 0;
	if (d < 0)
	{
		sign = 1;
		d = d * -1;
	}
	cnt = ft_count_digit(d);
	if (sign == 1)
	{
		arr = ft_strnew(++cnt);
		arr[0] = '-';
	}
	else
		arr = ft_strnew(cnt);
	while (d)
	{
		arr[--cnt] = (d % 10) + '0';
		d = d / 10;
	}
	return (arr);
}

char		*set_star_end(t_printf wh, char **s)
{
	char	*arr;
	int		cnt;
	int		i;
	int		j;

	cnt = 0;
	i = wh.loc + 1;
	while ((*s)[i++])
		cnt++;
	arr = ft_strnew(cnt);
	i = wh.loc;
	j = -1;
	while ((*s)[++i])
		arr[++j] = (*s)[i];
	return (arr);
}
