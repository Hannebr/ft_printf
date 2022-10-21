/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 16:32:52 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/19 21:48:47 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	len;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	dest = (char *) ft_calloc(len, sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strlcat(dest, s1, len);
	ft_strlcat(dest, s2, len);
	return (dest);
}
