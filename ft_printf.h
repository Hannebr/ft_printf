/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 15:05:59 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/24 16:43:03 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int				ft_printchar(va_list ptr);
int				ft_printstr(va_list ptr);
int				ft_printptr(va_list ptr);
int				ft_printdec(va_list ptr);
int				ft_printint(va_list ptr);
int				ft_printunsigned(va_list ptr);
int				ft_printhexlow(va_list ptr);
int				ft_printhexup(va_list ptr);
int				ft_printperc(va_list ptr);
void			print_base(char *baseset, int base, unsigned int n);
unsigned int	print_negative(int n);
int				ft_strlen(const char *s);
int				num_len(unsigned int n, int base);

#endif