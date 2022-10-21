/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 16:59:04 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/19 20:55:28 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	else
	{
		i = len - 1;
		while (i >= 0 && !(i > len))
		{
			*((char *)dst + i) = *((char *)src + i);
			i--;
		}
		return (dst);
	}
}
