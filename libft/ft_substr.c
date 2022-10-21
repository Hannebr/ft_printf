/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 15:23:35 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/19 20:42:35 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (len > ft_strlen(s))
		len = ft_strlen(s);
	result = (char *) ft_calloc((len + 1), sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len && (start + i) < ft_strlen(s))
	{
		result[i] = *((char *)s + (start + i));
		i++;
	}
	return (result);
}
