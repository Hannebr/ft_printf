/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 17:13:41 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/24 17:20:28 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

static int	(**function_array)(va_list arg);

static void	init_function_array(void)
{
	function_array = (int (**)(va_list)) malloc(9 * sizeof(int (*)(va_list)));
	function_array['c'] = ft_printchar;
	function_array['s'] = ft_printstr;
	function_array['p'] = ft_printptr;
	function_array['d'] = ft_printdec;
	function_array['i'] = ft_printint;
	function_array['u'] = ft_printunsigned;
	function_array['x'] = ft_printhexlow;
	function_array['X'] = ft_printhexup;
	function_array['%'] = ft_printperc;
}

int	ft_printf(const char *str, ...)
{
	unsigned int	i;
	va_list			ptr;
	int				length;

	init_function_array();
	va_start(ptr, str);
	i = 0;
	length = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			length += function_array[(int)str[i]](ptr);
		}
		else
		{
			write(1, &str[i], 1);
			length++;
		}
		i++;
	}
	free(function_array);
	return (length);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int res1 = ft_printf("does %c %s with %X?\n",'x',"work", 32759);
// 	int res2 = printf("does %c %s with %X?\n", 'x', "work", 32759);

// 	printf("my printf = %d,		original = %d\n", res1, res2);
// }
