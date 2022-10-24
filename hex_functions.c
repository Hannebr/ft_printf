/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hex_functions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 16:34:47 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/24 17:19:22 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_printhexlow(va_list ptr)
{
	unsigned int	num;
	int				length;

	num = va_arg(ptr, unsigned int);
	print_base("0123456789abcdef", 16, num);
	length = num_len(num, 16);
	return (length);
}

int	ft_printhexup(va_list ptr)
{
	unsigned int	num;
	int				length;

	num = va_arg(ptr, unsigned int);
	print_base("0123456789ABCDEF", 16, num);
	length = num_len(num, 16);
	return (length);
}

// int	ft_printptr(va_list ptr)
// {
// 	void	*address;
	
	
// }