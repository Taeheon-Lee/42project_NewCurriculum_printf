/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 16:16:26 by tlee              #+#    #+#             */
/*   Updated: 2020/04/23 20:47:43 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct	s_printf
{
	int		loc;
	int		flag_zero;
	int		flag_minus;
	int		wid;
	int		pre;
	int		size_res;
	int		size_tmp;
	int		sign;
	char	con;
	char	*res;
	char	*tmp;
}				t_printf;

int				ft_printf(const char *format, ...);
int				percent(const char *format, va_list ap);
int				percent_start(const char *format, int i, va_list ap);
int				percent_pass(t_printf wh, va_list ap);
int				percent_print(t_printf wh);
int				exit_percent(const char *format, int i);
t_printf		set_pre(t_printf wh, const char *s);
t_printf		set_wid(t_printf wh, const char *s);
t_printf		set_flag(t_printf wh, char c);
char			set_con(char c);
t_printf		case_c(t_printf wh, int c);
t_printf		case_s(t_printf wh, char *s);
t_printf		case_d(t_printf wh, long long int d);
t_printf		case_u(t_printf wh, unsigned long long int u);
t_printf		case_x(t_printf wh, unsigned long long int x);
t_printf		dtoa(t_printf wh, long long int d);
t_printf		utoa(t_printf wh, unsigned long long u);
t_printf		xtoa(t_printf wh, unsigned long long x);
t_printf		result_put(t_printf wh);
t_printf		result_set(t_printf wh);
t_printf		result(t_printf wh);
t_printf		result_apply_p(t_printf wh);
char			result_put_sign(t_printf wh);
t_printf		result_apply_sign(t_printf wh);
int				check_flag(char c);
int				check_num(char c);
int				check_dot(char c);

#endif
