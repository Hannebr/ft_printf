/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 13:11:16 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/24 15:22:47 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_printchar(va_list ptr)
{
	int	c;

	c = va_arg(ptr, int);
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(va_list ptr)
{
	int		length;
	char	*str;

	str = va_arg(ptr, char *);
	length = ft_strlen(str);
	write(1, str, length);
	return (length);
}

int	ft_printperc(va_list ptr)
{
	(void)ptr;
	write(1, "%", 1);
	return (1);
}
