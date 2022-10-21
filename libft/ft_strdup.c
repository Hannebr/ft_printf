/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:51:52 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/19 20:46:01 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		i;

	result = (char *) ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = *((char *)s1 + i);
		i++;
	}
	return (result);
}
