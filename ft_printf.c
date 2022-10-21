/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 17:13:41 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/21 17:44:32 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	ft_printchar(void *arg);
int	ft_printstr(void *arg);
int	ft_printptr(void *arg);
int	ft_printdec(void *arg);
int	ft_printint(void *arg);
int	ft_printunsigned(void *arg);
int	ft_printhexlow(void *arg);
int	ft_printhexup(void *arg);
int	ft_printperc(void *arg);

static const void (*function_array[9])(void *);

void	init_function_array(void)
{
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

	va_start(ptr, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			function_array[str[i + 1]] (va_arg(ptr, void *));
			i++;
		}
		i++;
	}
}