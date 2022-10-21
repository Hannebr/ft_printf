/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 13:28:03 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/19 20:49:31 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	get_word_length(size_t index, char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[index] != c && s[index])
	{
		index++;
		len++;
	}
	return (len);
}

static int	count_words(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (s[0] != c && s[0])
	{
		count = 1;
		i = 1;
	}
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

static char	**ft_free(int i, char **result)
{
	while (i >= 0)
	{
		free(result[i]);
		i--;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		count;
	int		i;
	size_t	index;
	size_t	word_len;

	count = count_words(s, c);
	result = (char **) malloc((count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	index = 0;
	while (i < count)
	{
		while (s[index] == c)
			index++;
		word_len = get_word_length(index, s, c);
		result[i] = ft_substr(s, index, word_len);
		if (result[i] == NULL)
			return (ft_free(i, result));
		i++;
		index += word_len;
	}
	result[i] = NULL;
	return (result);
}
