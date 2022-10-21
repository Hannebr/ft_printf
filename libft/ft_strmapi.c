/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 11:13:41 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/19 20:44:11 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	length;
	char			*dest;

	length = ft_strlen(s);
	dest = (char *) ft_calloc((length + 1), sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		dest[i] = (*f)(i, s[i]);
		i++;
	}
	return (dest);
}
