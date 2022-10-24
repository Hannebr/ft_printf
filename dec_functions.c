/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dec_functions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 14:55:42 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/24 16:22:20 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_printdec(va_list ptr)
{
	int				n;
	unsigned int	num;
	int				length;

	n = va_arg(ptr, int);
	num = print_negative(n);
	print_base("0123456789", 10, num);
	length = num_len(num, 10);
	if (n <= 0)
		length++;
	return (length);
}

int	ft_printint(va_list ptr)
{
	return (ft_printdec(ptr));
}

int	ft_printunsigned(va_list ptr)
{
	unsigned int	num;

	num = va_arg(ptr, unsigned int);
	print_base("0123456789", 10, num);
	return (num_len(num, 10));
}