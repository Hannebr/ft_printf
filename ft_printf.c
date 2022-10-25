/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 17:13:41 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/25 12:18:08 by hbrouwer      ########   odam.nl         */
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
	unsigned int	i;
	va_list			ptr;
	int				length;
	int				res;

	va_start(ptr, str);
	i = 0;
	length = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			length += g_function_array[(int)str[i]](ptr);
		}
		else
		{
			res = write(1, &str[i], 1);
			if (res == -1)
				return (res);
			length++;
		}
		i++;
	}
	return (length);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int res1 = ft_printf("%%%\n");
// 	int res2 = printf("%%%\n");

// 	printf("my printf = %d,		original = %d\n", res1, res2);
// }
