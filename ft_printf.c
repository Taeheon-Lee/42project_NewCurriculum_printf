#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    va_list ap;
    int     result;

    va_start(ap, format);
    result = percent(format, ap);
    va_end(ap);
    return (result);
}
