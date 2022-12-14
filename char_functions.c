/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 13:11:16 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/25 17:06:05 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_printchar(va_list ptr)
{
	int	c;
	int	res;

	c = va_arg(ptr, int);
	res = write(1, &c, 1);
	return (res);
}

int	ft_printstr(va_list ptr)
{
	int		length;
	char	*str;

	str = va_arg(ptr, char *);
	if (str == NULL)
	{
		length = write(1, "(null)", 6);
		return (length);
	}
	length = write(1, str, ft_strlen(str));
	return (length);
}

int	ft_printperc(va_list ptr)
{
	int	res;

	(void)ptr;
	res = write(1, "%", 1);
	return (res);
}
