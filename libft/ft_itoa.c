/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 15:49:18 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/19 21:15:30 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	num_len(int n)
{
	size_t	length;

	length = 0;
	if (n <= 0)
		length++;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static char	*convert_to_str(char *dest, int n, size_t length)
{
	int				i;
	unsigned int	tmp;

	i = length - 1;
	if (n < 0)
		tmp = n * -1;
	else
		tmp = n;
	dest[length] = '\0';
	while (i >= 0)
	{
		dest[i] = (tmp % 10) + '0';
		tmp /= 10;
		i--;
	}
	if (n < 0)
		dest[0] = '-';
	return (dest);
}

char	*ft_itoa(int n)
{
	size_t	length;
	char	*str;

	length = num_len(n);
	str = (char *) malloc((length + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	str = convert_to_str(str, n, length);
	return (str);
}
