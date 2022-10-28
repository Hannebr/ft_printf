/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 17:13:41 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/28 12:10:09 by hbrouwer      ########   odam.nl         */
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

// #include <stdio.h>

// int	main(void)
// {
// 	int res1 = ft_printf("Does %c %s with %d (%X)\n", 'x', NULL, 42424, 42424);
// 	int res2 = printf("Does %c %s with %d (%X)\n", 'x', NULL, 42424, 42424);
// 	int res1 = ft_printf("hello %");
// 	int res2 = printf("hello %");

// 	printf("\nmy result = %d		original = %d\n", res1, res2);
// }
