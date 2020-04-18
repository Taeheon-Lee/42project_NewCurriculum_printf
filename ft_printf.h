#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define Check_flag(c) (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#')
# define Check_num(c) (c >= '1' && c <= '9')
# define Check_dot(c) (c == '.')
# define Check_len(c) (c == 'h' || c == 'L' || c == 'l' || c == 'j' || c == 'z')
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct  s_printf
{
    int     loc;
    int     flag_zero;
    int     flag_minus;
    int     wid;
    int     pre;
    int     size_res;
    int     size_val;
    int     sign;
    char    con;
    char    *res;
    char    *val;
}               t_printf;

int                     ft_printf(const char *format, ...);
int                     percent(const char *format, va_list ap);
int                     percent_start(const char *format, int i, va_list ap);
int                     percent_pass(t_printf f, va_list ap);
char                    set_con(char c);
t_printf                set_flag(t_printf f, char c);
t_printf                set_wid(t_printf f, const char *s);
t_printf                set_pre(t_printf f, const char *s);
t_printf                case_c(t_printf f, int c);
t_printf                case_s(t_printf f, char *s);
t_printf                case_d(t_printf f, long long int d);
t_printf                case_u(t_printf f, unsigned long long int u);
t_printf                case_x(t_printf f, unsigned long long int x);
t_printf                dtoa(t_printf f, long long int d);
t_printf                utoa(t_printf f, unsigned long long int u);
t_printf                xtoa(t_printf f, unsigned long long int x);
char                    *get_front(t_printf f, long double i);
char                    *get_back(t_printf f, long double i);
t_printf                result_put(t_printf f);
t_printf                result_set(t_printf f);
t_printf                result(t_printf f);
t_printf                result_flag_p(t_printf f);
char                    result_flag_set_sign(t_printf f);
t_printf                result_flag_sign(t_printf f);

#endif
