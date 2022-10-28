/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 17:13:41 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/28 13:26:15 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

static int	(*g_function_array[])(va_list arg) = {
['c'] = ft_printchar,
['s'] = ft_printstr,
['p'] = ft_printptr,
['d'] = ft_printdec,
['i'] = ft_printint,
['u'] = ft_printunsigned,
['x'] = ft_printhexlow,
['X'] = ft_printhexup,
['%'] = ft_printperc
};

int	ft_printf(const char *str, ...)
{
	int			i;
	int			len;
	va_list		ptr;

	va_start(ptr, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (ft_strchr("cspdiuxX%", str[i + 1]))
				len += g_function_array[(int)str[i + 1]](ptr);
			i++;
		}
		else if (str[i] != '%')
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	return (len);
}

// int main(void)
// {
//   int printed_chars = 0;
//   int my_printed_chars = 0;
//   printed_chars = printf("printing non-existing format specifier: %l with system printf\n");
//   my_printed_chars = ft_printf("printing non-existing format specifier: %l with my ft_printf \n");
//   printf("\n(number of printed chars with system printf: %i)\n", printed_chars);
//   printf("(number of printed chars with my ft_printf:  %d)\n", my_printed_chars);
//   return (0);
// }
